#include "cv.h"
#include "highgui.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include <iostream>
using namespace std;

int main()
{
	/** ��������Ƶ�ļ� */
	cv::VideoCapture vc;
	vc.open( "./4.mp4" );

	if ( vc.isOpened() )
	{
		/** �������Ƶ�ļ� */
		cv::VideoWriter vw;
		vw.open( "./output.avi", // �����Ƶ�ļ���
			-1, // Ҳ����ΪCV_FOURCC_PROMPT��������ʱѡȡ
			25.0, // ��Ƶ֡��
			cv::Size( (int)vc.get( CV_CAP_PROP_FRAME_WIDTH ), (int)vc.get( CV_CAP_PROP_FRAME_HEIGHT ) ), // ��Ƶ��С
			true ); // �Ƿ������ɫ��Ƶ

		/** ����ɹ��������Ƶ�ļ� */
		if ( vw.isOpened() )
		{
			while ( true )
			{
				/** ��ȡ��ǰ��Ƶ֡ */
				cv::Mat frame;
				vc >> frame;

				/** ����Ƶ��ȡ��ϣ�����ѭ�� */
				if ( frame.empty() )
				{
					break;
				}

				/** ����Ƶд���ļ� */
				vw << frame;
			}
		}
	}

	/** �ֶ��ͷ���Ƶ������Դ */
	vc.release();

	return 0;
}
