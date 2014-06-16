#include "unity.h"
#include "CircularBuffer.h"
#include "CException.h"

void setUp(void)
{
}

void tearDown(void)
{
}




void test_circularBufferNew_given_6_should_allocate_CircularBuffer_object_with_a_buffer_of_6(void){
	CircularBuffer *cb = circularBufferNew(6);
	
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(6, cb->length);
	TEST_ASSERT_EQUAL(0, cb->size);
	TEST_ASSERT_EQUAL_PTR(cb->buffer, cb->head);
	TEST_ASSERT_EQUAL_PTR(cb->buffer, cb->tail);
	
	circularBufferDel(cb);
}


void test_circularBufferAdd_given_length3_and_add_3value_should_not_give_error(void){
	CircularBuffer *cb = circularBufferNew(3);
	
    CEXCEPTION_T	err;
	Try {			
		    circularBufferAdd(cb, 9);
			circularBufferAdd(cb, 9);
			circularBufferAdd(cb, 9);
		
		printf("Success: No exception generated.\n");
	} Catch(err) {
		TEST_FAIL_MESSAGE("Do not expect exception to be generated.")	
	}	
}


void test_circularBufferAdd_given_length4_and_add_5_number_should_give_full_buffer_error(void){
	CircularBuffer *cb = circularBufferNew(4);

	CEXCEPTION_T err;

	Try{
			circularBufferAdd( cb, 9 );
			circularBufferAdd( cb, 9 );
			circularBufferAdd( cb, 9 );
			circularBufferAdd( cb, 9 );
			circularBufferAdd( cb, 9 );		
	}	Catch(err) 	{   
				TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
				printf("Success: Exception generated. Error code: %d.\n", err);
		}
}

void test_circularBufferRemove_given_length2_remove_2value_should_not_give_error(void){
	CircularBuffer *cb = circularBufferNew(2);
   
    CEXCEPTION_T	err;
	
	int PopData;

	Try {				    
			circularBufferAdd(cb, 9);
			circularBufferAdd(cb, 9);
			PopData = circularBufferRemove(cb);
			printf("Success: No exception generated.\n");
		
	} Catch(err) {
			TEST_FAIL_MESSAGE("Do not expect exception to be generated.")	
				}				
}




void test_circularBufferRemove_given_length0_should_give_buffer_empty_error(void){
	CircularBuffer *cb = circularBufferNew(0);
	
	CEXCEPTION_T err;
	
	Try{
		circularBufferRemove(cb);
	}Catch(err){
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_EMPTY, err);
		printf("Success: Exception generated. Error code: %d.\n", err);
	}
}



