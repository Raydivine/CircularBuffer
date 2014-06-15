#include "unity.h"
#include "CircularBuffer.h"
#include "CException.h"

void setUp(void)
{
}

void tearDown(void)
{
}


void test_circularBufferNew_given_6_should_allocate_CircularBuffer_object_with_a_buffer_of_6(void) {

	CircularBuffer *cb = circularBufferNew(6);
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(6, cb->length);
	TEST_ASSERT_EQUAL(0, cb->size);
	TEST_ASSERT_EQUAL_PTR(cb->buffer, cb->head);
	TEST_ASSERT_EQUAL_PTR(cb->buffer, cb->tail);	
	circularBufferDel(cb);
	
}

void test_circulrBufferAdd_given_length6and_add_OneNumber_should_add_2_to_the_tail(void){
    
	circularBufferNew(6);
	struct Buffer CircularBuffer;
	
    CEXCEPTION_T	err;
	Try {
		circularBufferAdd( &CircularBuffer, 2 ) ;
		printf("Success: No exception generated.\n");
	} Catch(err) {
		TEST_FAIL_MESSAGE("Do not expect exception to be generated.")	
	}	
}
	
void test_circulrBufferAdd_given_length5_and_add_6Number_should_given_full_buffer_error(void){
    
	circularBufferNew(5);
	struct Buffer CircularBuffer;
	
    CEXCEPTION_T	err;
	Try {
		circularBufferAdd( &CircularBuffer, 1 ) ;
		circularBufferAdd( &CircularBuffer, 2 ) ;
		circularBufferAdd( &CircularBuffer, 3 ) ;
		circularBufferAdd( &CircularBuffer, 4 ) ;
		circularBufferAdd( &CircularBuffer, 5 ) ;
		circularBufferAdd( &CircularBuffer, 6 ) ;
		TEST_FAIL_MESSAGE("Should generate an error due to full buffer.")
	} Catch(err) {
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
	}	
}


void test_circulrBufferAdd_given_length0_and_add_2Number_should_given_null_buffer_error(void){
   
     circularBufferNew(0);
	 struct Buffer CircularBuffer;

	 CEXCEPTION_T	err;
	Try {
		circularBufferAdd( &CircularBuffer, 4 ) ;
		circularBufferAdd( &CircularBuffer, 5 ) ;
		TEST_FAIL_MESSAGE("Should generate an error due to null buffer.")
	} Catch(err) {
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_EMPTY, err);	
	}	
}


void test_circularBufferRemove_given_length1_and_remove_1Number_should_set_to_null(void){
   
     circularBufferNew(1);
	 struct Buffer CircularBuffer;

	 CEXCEPTION_T	err;
	Try {
		circularBufferRemove(&CircularBuffer) ;
		TEST_FAIL_MESSAGE("Should generate an error due to null buffer.")
	} Catch(err) {
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_EMPTY, err);	
	}	
}




