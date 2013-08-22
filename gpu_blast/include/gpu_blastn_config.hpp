#ifndef __GPU_BLASTN_CONFIGU_H__
#define __GPU_BLASTN_CONFIGU_H__  



#ifdef PRE_VERSION
#define GPU_RUN  1

#define GPU_RUN_SCAN_v1 0

#define GPU_RUN_SCAN_v1_KERNEL_v1 1

// any ���Ը�ǰ���kernelһ���ã�����ɳ����Լ�ѡ��
#define GPU_RUN_SCAN_v1_KERNEL_ANY 1

///////////////////////////////////////////////////////////////////////////
// scan v1 �Ǹ� ext v2��ϵġ�

#define GPU_EXT_RUN  1

#define GPU_EXT_RUN_V1 0

#define GPU_EXT_RUN_V2 1


#define ONE_VOL 0

//////////////////////////////////////////////////////////////////////////
#define USE_OPENMP 0

#define MULTI_QUERIES 1

#endif

//////////////////////////////////////////////////////////////////////////
#define OPT_TRACEBACK 1
//////////////////////////////////////////////////////////////////////////

#endif // __GPU_BLASTN_CONFIGU_H__