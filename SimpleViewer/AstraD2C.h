#pragma once
#include "d2cSwapper.h"
#include "ObCommon.h"

class AstraD2C :public d2cSwapper
{
public:
	AstraD2C();
	virtual ~AstraD2C();

	//�������ܣ������ʼ��
	int CameraInit(int d2cType);

	//�������ܣ�����D2C����
	int SetD2CType(int decType);

	//�������ܣ��������ʼ��
	int CameraUnInit(void);

	//�������ܣ���ȡ���������
	int GetStreamData(cv::Mat &cv_rgb, cv::Mat &cv_depth);

	//�������ܣ�ֹͣ��
	int StreamStop(void);

	//��������: ��ȡ����������
	//������
	//[out] cameraParam: ����������
	//����ֵ��0:��ʾOK; ��0��ʾ��ȡ����ʧ��
	int GetCameraParam(OBCameraParams &cameraParam);

	//�������ܣ���ȡDepth�ֱ���
	//������
	//����[Out] nImageWidth: ͼ���;
	//����[Out] nImageHeight: ͼ���;
	//����ֵ���ɹ����� CAMERA_STATUS_SUCCESS��ʧ�ܷ��� CAMERA_STATUS_DEPTH_GET_RESOLUTION_FAIL
	int GetCameraResolution(int &nImageWidth, int &nImageHeight);
	int GetSoftCameraResolution(int &nImageWidth, int &nImageHeight);

	//�������ܣ���ȡ�豸��pid
	uint16_t GetDevicePid(void);

private:

	/**** start depth swapper ****/
	int DepthInit(void);
	int DepthUnInit();

	int Depthstart(int width, int height);
	int Depthstop();
	int WaitDepthStream(VideoFrameRef &frame);
	void CalcDepthHist(VideoFrameRef& frame);
	bool IsLunaDevice(void);

	//depth data
	Device m_device;

	VideoStream m_depthStream;
	//openni::VideoFrameRef m_depthFrame;
	bool m_bDepthInit;
	bool m_bDepthStart;

	bool m_bDepStreamCreate;


	float* m_histogram;
	int m_ImageWidth;
	int m_ImageHeight;

	/***end depth swapper********/

	/****start color swapper****/
	int ColorStart(int width, int height);
	int ColorStop();
	int WaitColorStream(VideoFrameRef &frame);

	VideoStream m_ColorStream;
	//openni::VideoFrameRef m_ColorFrame;
	bool m_bColorStart;
	bool m_bColorStreamCreate;
	/***end color swapper ******/

private:

	
};

