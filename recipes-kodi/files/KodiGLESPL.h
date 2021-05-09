#ifndef _KodiGLESVuplusPL_H_
#define _KodiGLESVuplusPL_H_

#ifdef __cplusplus
extern "C" {
#endif

void GLES_Native_Init(void);

bool GLES_Native_CreateNativeDisplay(void** display);
void* GLES_Native_CreateNativeWindow(void);

void GLES_Native_DestroyNativeDisplay(void);
void GLES_Native_DestroyNativeWindow(void);

#ifdef __cplusplus
}
#endif

#endif /*_KodiGESVuplusPL_H_*/

