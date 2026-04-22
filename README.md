# openni-rgbd
利用奥比中光 的 Aster Pro 相机 openni 库，保存rgbd 文件
按照官方说明，cmake 不行
把所有的第三方库，的X64版本，手动添加后，常规的三个目录后可行


增加的按键的事件，3 开始截图 4 停止截图

1 2是默认的esc退出

改源代码一行  332行	
//cv::addWeighted(imgROI, 0.5, CaliDepthHistogram, 0.5, 0.0, imgROI);
注销掉这一行就能看到rgb图，不注销，rgb跟depth的一起混

增加图像保存
if (bCapture){
	// cv::imwrite('a.jpg',IplColor);
	// cv::imwrite('b.jpg',IplDepth);
	const std::string rgbfilename =std::string("./rgb/rgb_")+std::to_string(nCaptureNo)+std::string(".png");
	const std::string depthfilename = std::string("./depth/depth_") + std::to_string(nCaptureNo) + std::string(".png");
	//std::cout << rgbfilename << std::endl;
	cv::imwrite(rgbfilename, cv_rgb);
	//cv::imwrite(depthfilename, CaliDepthHistogram);
	cv::imwrite(depthfilename, cv_depth);
	nCaptureNo += 1;
	printf("CCCCCCCCCCCC");
}

把这个图保存之后，用code-open3d，那个文件夹的test6.py，就可以实现rgbd图像的三维重建，目前测试可行，但效果不怎么样
