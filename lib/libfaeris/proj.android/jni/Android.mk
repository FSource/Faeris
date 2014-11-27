LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE :=faeris_static


LOCAL_CFLAGS :=     -I$(LOCAL_PATH)/../../src \
 					-I$(LOCAL_PATH)/../../src/support \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/freetype/include \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/GL/include \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/libpng/include \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/zlib/include \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/libtga/src \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/minizip/include \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/curl/include_android \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/fmod/include \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/jsonc/src \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/libjpeg/include.android \
 					-I$(LOCAL_PATH)/../../../lib3rdparty/glslext/src/ 		\
 					-I$(LOCAL_PATH)/../../../lib3rdparty/libmd5model/src/ 		\



LOCAL_SRC_FILES :=  \
					src/com_faeris_lib_Fs_Jni.cc \
					../../src/FsGlobal.cc \
					../../src/FsObject.cc \
					../../src/FsFaerisModule.cc \
					../../src/extends/FsScriptEngine.cc \
					../../src/stage/FsActionTarget.cc \
					../../src/stage/entity/transform/FsEulerTransform.cc \
					../../src/stage/entity/transform/FsQuaternionTransform.cc \
					../../src/stage/entity/FsIMaterial2DEntity.cc \
					../../src/stage/entity/transform/FsEulerTransform.cc \
					../../src/stage/entity/transform/FsQuaternionTransform.cc \
					../../src/stage/entity/FsEntity.cc \
					../../src/stage/entity/FsLabelTTF.cc \
					../../src/stage/entity/FsQuad2D.cc \
					../../src/stage/entity/FsSprite2DData.cc \
					../../src/stage/entity/FsSprite2D.cc \
					../../src/stage/entity/FsLabelBitmap.cc \
					../../src/stage/entity/FsParticle2DEmitter.cc \
					../../src/stage/entity/FsParticle2DEffect.cc \
					../../src/stage/entity/FsVertexPolygon.cc \
					../../src/stage/entity/FsPanel.cc \
					../../src/stage/ui/FsDynamicView.cc \
					../../src/stage/ui/FsListView.cc \
					../../src/stage/ui/FsPageView.cc \
					../../src/stage/ui/FsPressButton.cc \
					../../src/stage/ui/FsScroller.cc \
					../../src/stage/ui/FsScrollView.cc \
					../../src/stage/ui/FsScrollWidget.cc \
					../../src/stage/ui/FsStateButton.cc \
					../../src/stage/ui/FsToggleButton.cc \
					../../src/stage/ui/FsUiWidget.cc \
					../../src/stage/ui/FsVelocityTracker.cc \
					../../src/stage/layer/FsColorLayer.cc \
					../../src/stage/layer/FsLayer.cc \
					../../src/stage/layer/FsLayer2D.cc \
					../../src/stage/FsScene.cc \
					../../src/stage/FsDirector.cc \
					../../src/graphics/FsColor.cc \
					../../src/graphics/FsFontTTF.cc \
					../../src/graphics/FsImage2D.cc \
					../../src/graphics/FsRenderDevice.cc \
					../../src/graphics/FsFrameBuffer.cc \
					../../src/graphics/FsTexture2D.cc \
					../../src/graphics/FsFontBitmap.cc \
					../../src/graphics/FsVertexBuffer.cc \
					../../src/graphics/shader/FsProgram.cc \
					../../src/graphics/shader/FsProgramSource.cc \
					../../src/graphics/shader/FsProgramFeatureDesc.cc \
					../../src/graphics/shader/FsUniformValue.cc \
					../../src/graphics/material/FsMaterial.cc \
					../../src/graphics/material/FsMaterial2D.cc \
					../../src/sys/event/FsSysDispatcher.cc \
					../../src/sys/event/FsTouchDispatcher.cc \
					../../src/sys/event/FsKeypadDispatcher.cc \
					../../src/sys/event/FsInputTextDispatcher.cc \
					../../src/sys/io/FsFile.cc \
					../../src/sys/io/FsSysFile.cc \
					../../src/sys/io/FsVFS.cc \
					../../src/sys/io/FsPackage.cc \
					../../src/sys/io/FsZipPackage.cc \
					../../src/sys/io/FsFgzPackage.cc \
					../../src/sys/io/FsMemFile.cc \
					../../src/sys/io/FsSegFile.cc  \
					../../src/sys/thread/FsThread.cc \
					../../src/sys/thread/FsSemaphore.cc \
					../../src/sys/thread/FsMutex.cc \
					../../src/sys/network/FsHttpEngine.cc \
					../../src/sys/network/FsHttpReponse.cc \
					../../src/sys/network/FsHttpRequest.cc \
					../../src/sys/FsSys.cc \
					../../src/sys/platform/android/FsJniUtil.cc \
					../../src/sys/FsTimer.cc \
					../../src/sys/FsWindow.cc \
					../../src/math/FsMath.cc \
					../../src/math/FsMathUtil.cc \
					../../src/math/FsMatrix4.cc \
					../../src/math/FsRect2D.cc \
					../../src/math/FsBox3D.cc \
					../../src/math/FsQuaternion.cc \
					../../src/math/curve/FsCatmullRomCurve.cc \
					../../src/math/curve/FsCubicBezierCurve.cc \
					../../src/math/curve/FsLinearCurve.cc \
					../../src/math/easing/FsBackEase.cc \
					../../src/math/easing/FsBezierEase.cc \
					../../src/math/easing/FsBounceEase.cc \
					../../src/math/easing/FsCircleEase.cc \
					../../src/math/easing/FsCubicEase.cc \
					../../src/math/easing/FsEaseExpr.cc \
					../../src/math/easing/FsEasingUtil.cc \
					../../src/math/easing/FsElasticEase.cc \
					../../src/math/easing/FsExponentialEase.cc \
					../../src/math/easing/FsLinearEase.cc \
					../../src/math/easing/FsPowerEase.cc \
					../../src/math/easing/FsQuadEase.cc \
					../../src/math/easing/FsQuartEase.cc \
					../../src/math/easing/FsQuintEase.cc \
					../../src/math/easing/FsSineEase.cc \
					../../src/mgr/FsFontTTFMgr.cc \
					../../src/mgr/FsResource.cc \
					../../src/mgr/FsResourceMgr.cc \
					../../src/mgr/FsTextureMgr.cc \
					../../src/mgr/FsSprite2DDataMgr.cc \
					../../src/mgr/FsProgramSourceMgr.cc \
					../../src/scheduler/FsScheduler.cc \
					../../src/scheduler/FsSchedulerTarget.cc \
					../../src/scheduler/FsTask.cc \
					../../src/support/data/FsBase64.cc \
					../../src/support/data/FsDeflate.cc \
					../../src/support/data/FsHash.cc \
					../../src/support/data/FsIconv.cc \
					../../src/support/data/FsUnicode.cc \
					../../src/support/data/FsZipReader.cc \
					../../src/support/data/FsFgzReader.cc \
					../../src/support/data/FsEncrypt.cc \
					../../src/support/data/FsMd5.cc \
					../../src/support/data/FsJson.cc \
					../../src/support/felis/sl_comment.cc \
					../../src/support/felis/sl_double_quote_str.cc \
					../../src/support/felis/sl_simple_str.cc \
					../../src/support/felis/sl_single_quote_str.cc \
					../../src/support/felis/sl_specific_symbol.cc \
					../../src/support/felis/sl_top.cc \
					../../src/support/felis/sl_white_space.cc \
					../../src/support/felis/xir_file.cc \
					../../src/support/felis/xir_grammer.cc \
					../../src/support/felis/xir_parser.cc \
					../../src/support/felis/xir_scanner.cc \
					../../src/support/felis/xir_token.cc \
					../../src/support/image/FsImageDecoder.cc \
					../../src/support/image/FsImageFaw.cc  \
					../../src/support/image/FsImageJpeg.cc \
					../../src/support/image/FsImagePng.cc \
					../../src/support/image/FsImageTga.cc \
					../../src/support/util/FsArray.cc \
					../../src/support/util/FsDict.cc \
					../../src/support/util/FsSlowDict.cc \
					../../src/support/util/FsLog.cc \
					../../src/support/util/FsPathUtil.cc \
					../../src/support/util/FsScriptUtil.cc \
					../../src/support/util/FsSlowArray.cc \
					../../src/support/util/FsString.cc \
					../../src/support/util/FsInteger.cc \
					../../src/media/FsAudioEngine.cc \
					../../src/media/FsAudioPlayer.cc \
					../../src/stage/action/FsAction.cc \
					../../src/stage/action/FsCurve3Action.cc \
					../../src/stage/action/FsFixTimeAction.cc \
					../../src/stage/action/FsLoopAction.cc \
					../../src/stage/action/FsMoveAction.cc \
					../../src/stage/action/FsPauseAction.cc \
					../../src/stage/action/FsRotateAction.cc \
					../../src/stage/action/FsScaleAction.cc \
					../../src/stage/action/FsSeqAction.cc \





include $(BUILD_STATIC_LIBRARY)



