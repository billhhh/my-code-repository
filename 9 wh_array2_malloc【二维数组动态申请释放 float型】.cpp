#include <malloc.h>

//��̬�����ά����ռ䣬N*M
void wh_array2_malloc(int N,int M,float **array)
{
	array = (float **)malloc(sizeof(float *)*N);
	for (int i=0; i<N; i++)
		array[i] = (float *)malloc(sizeof(float)*M);
}

//�ͷŶ�ά����ռ�
void wh_array2_malloc_free(int N,int M,float **array)
{
	for (int i=0; i<N; i++)
		free((void *)array[i]);
	free((void *)array);
}