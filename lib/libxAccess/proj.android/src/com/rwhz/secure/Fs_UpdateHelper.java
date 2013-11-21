package com.rwhz.secure;

import java.io.File;

import org.apache.http.HttpResponse;
import org.apache.http.util.EntityUtils;
import org.json.JSONObject;


import com.faeris.lib.Fs_Application;
import com.huizhi.libpay.R;
import com.rwhz.android.SysUtil;
import com.rwhz.minder.Fs_r3rdPartyJni;
import com.rwhz.net.HttpAsync;
import com.rwhz.net.HttpCallback;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.os.Handler;
import android.os.Message;
import android.util.Log;



public class Fs_UpdateHelper {
	
	public static final String TAG  = "Delo";
	
	public static final int RQF_INSTALL_CHECK = 4;
	public static final int RQF_INSTALL_FAIL = -1;
	public static final int RQF_INSTALL_SUCCESS = 1;

	
//	private ProgressDialog mProgress = null;
   private  Context mContext = null;
   private Fs_UpdateInfo mInfo  = null;
   
   private boolean  mDownlock = false;
   private  long mObjADD ;
   
	public Fs_UpdateHelper(Context context){
		mContext = context;
		mDownlock = false;
	}
	
	public void checkUpdate( long objADD)
	{
			mObjADD = objADD;
						
			//  模拟 成功计费。 这里需要 调用计费接口 。 
			
			Fs_Application.runOnEngineThread(new Runnable() {
				@Override
				public void run() {
					// TODO Auto-generated method stub
					Fs_r3rdPartyJni.NativeCheckUpdateCB(mObjADD, 100);
				}
			});					
			
	}
	
	public void askSeverNewUpdate()
	{		
		// 实例新线程检测是否有新版本进行下载		
		HttpAsync httpAsync = new HttpAsync();
		
		int versionCode = SysUtil.getVersionCode(mContext);
		
		int channel = SysUtil.getAppInterMeta(mContext, "CHANNEL");
		
		String packageName = SysUtil.getPackageName(mContext);
	
		String url  = mContext.getResources().getString(R.string.updateUrl);
		
		url = url + "pn="+packageName+"&ver="+ versionCode + "&platId="+channel;
		
		Log.i(TAG, "update : url :" + url);
		
		httpAsync.setUrl(url);
		
		httpAsync.setHttpCallback(new HttpCallback(){
			 		public void onSuccess(HttpResponse response)
			 		{//...请求成功后的处理
			 							 			
			 			try {
			 				
			 		       String content = EntityUtils.toString(response.getEntity(),"UTF-8");			 		       
			 				Fs_UpdateInfo Info = new Fs_UpdateInfo();			 				
				 			JSONObject req = new JSONObject(content);				 							 			
				 			
				 			Info.setApkUrl(req.getString("url"));
				 			Info.setIsForce(req.getInt("isForce"));
				 			Info.setMsg(req.getString("msg"));
				 			Info.setResult(req.getInt("ret"));
				 			Info.setVersion(req.getInt("version"));							 			
											 				
				 			if(Info.getResult() == 0 )
				 			{
				 				if(Info.getApkUrl().length() > 0)
				 					SendMessage(Fs_UpdateHelper.RQF_INSTALL_CHECK , Info);				 				
				 				else
				 					SendMessage(Fs_UpdateHelper.RQF_INSTALL_SUCCESS , Info);				 								 					
				 			}
				 			else
					 			SendMessage(Fs_UpdateHelper.RQF_INSTALL_FAIL , Info.getMsg());	
				 			
						} catch (Exception e) {
							// TODO Auto-generated catch block							
				 			SendMessage(Fs_UpdateHelper.RQF_INSTALL_FAIL ,"获取网络数据异常");						 							  			
							
							e.printStackTrace();
						}
			 			
			  		}
			  		public void onFail(int errorCode, String errorMessage)
			  		{//...请求失败后的处理
			 			SendMessage(Fs_UpdateHelper.RQF_INSTALL_FAIL ,errorMessage);						 							  			
			  		}
			  	});
			  	//...设置表单项目和头项目
			  	httpAsync.get();
	}
	
	@SuppressWarnings("unused")
	private static void FileDownloadeUrl(Context context , String url)
	{
		FileDownloader fd = new FileDownloader();
		File cacheDir = context.getCacheDir();
		
		final String cachePath = cacheDir.getAbsolutePath() + "/game.apk";

		fd.setFileUrl(url);
		fd.setSavePath(cachePath);
		
		fd.setProgressOutput(new FileDownloader.IDownloadProgress() {
			
			@Override
			public void downloadSucess() {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void downloadProgress(float progress) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void downloadFail() {
				// TODO Auto-generated method stub
				
			}
		});
		fd.start();		
	}
	//
	// the handler use to receive the install check result.
	// 此处接收安装检测结果
	private Handler mHandler = new Handler() {
		public void handleMessage(Message msg) {
			try {
				switch (msg.what) {
				
					case Fs_UpdateHelper.RQF_INSTALL_CHECK: {
						//	可以更新				
						mInfo = (Fs_UpdateInfo) msg.obj;					
						
						showInstallConfirmDialog(mContext,"");
					}
					break;
						
					case Fs_UpdateHelper.RQF_INSTALL_SUCCESS:
					{//成功
						setDownlock(false);
					}
					break;
					case Fs_UpdateHelper.RQF_INSTALL_FAIL:{
						//有错误，或者不需要更新
						String Eerromsg = (String)msg.obj;						
						Log.i(TAG, Eerromsg);
					}
					break;
				}				
				super.handleMessage(msg);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	};
	
	private void SendMessage(int what, Object obj)
	{
		Message msg = new Message();
		msg.what = what;
		msg.obj = obj;
		mHandler.sendMessage(msg);
	}
	
	
	/**
	 * 显示确认安装的提示
	 * 
	 * @param context
	 *            上下文环境
	 * @param cachePath
	 *            安装文件路径
	 */
	public void showInstallConfirmDialog(final Context context,
			final String cachePath) {
		AlertDialog.Builder tDialog = new AlertDialog.Builder(context);
//		tDialog.setIcon(R.drawable.info);
		tDialog.setTitle(context.getResources().getString(
				R.string.confirm_install_hint));
		tDialog.setMessage(context.getResources().getString(
				R.string.confirm_install));

		tDialog.setPositiveButton(R.string.Ensure,
				new DialogInterface.OnClickListener() {
					public void onClick(DialogInterface dialog, int which) {						
						//						
						SysUtil.browserInterface(mContext, mInfo.getApkUrl());
						setDownlock(true);
						
//						FileDownloadeUrl(mInfo.getApkUrl());
					}
				});

		tDialog.setNegativeButton(
				context.getResources().getString(R.string.Cancel),
				new DialogInterface.OnClickListener() {
					public void onClick(DialogInterface dialog, int which) {
						
					}
				});

		tDialog.show();
	}

	public boolean isDownlock() {
		return mDownlock;
	}

	public void setDownlock(boolean downlock) {
		mDownlock = downlock;
	}
	

}
