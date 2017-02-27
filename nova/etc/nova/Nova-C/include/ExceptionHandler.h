#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H

#include <stdio.h>
#include <setjmp.h>

#define buffer jmp_buf
#define setJump setjmp
#define jump longjmp

#define TRY \
	{\
		buffer buf;\
		int exception_code;\
		\
		nova_exception_Nova_ExceptionData* newData = novaEnv.nova_exception_ExceptionData.ExceptionData(0, &buf);\
		\
		if (exceptionData != 0)\
		{\
			newData->nova_exception_Nova_ExceptionData_Nova_parent = exceptionData;\
		}\
		\
		exceptionData  = newData;\
		exception_code = setJump(buf);\
		\
		if (exception_code == 0)

#define CATCH(x)\
	else if (nova_meta_Nova_Class_Nova_isOfType(exceptionData->nova_exception_Nova_ExceptionData_Nova_thrownException->vtable->classInstance, x))

#define FINALLY

#define END_TRY \
		{\
			nova_exception_Nova_ExceptionData* oldData = exceptionData;\
			nova_exception_Nova_ExceptionData* newData = exceptionData->nova_exception_Nova_ExceptionData_Nova_parent;\
			if (newData != 0)\
			{\
				exceptionData = newData;\
			}\
			if (oldData != 0)\
			{\
				NOVA_FREE(oldData);\
			}\
		}\
	}

#define THROW(exception, soft) novaEnv.nova_exception_ExceptionData.throwException(exceptionData, &exceptionData, (nova_exception_Nova_Exception*)exception, soft)

#endif