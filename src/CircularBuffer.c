#include "stdio.h"
#include "malloc.h"
#include "CircularBuffer.h"
#include "CException.h"




CircularBuffer *circularBufferNew(int length){
	
	CircularBuffer *circularBuffer;
	
	circularBuffer = malloc(sizeof(CircularBuffer));
	circularBuffer->buffer = malloc(sizeof(int) * length);
	circularBuffer->length = length;
	circularBuffer->size = 0;
	circularBuffer->head = circularBuffer->buffer;
	circularBuffer->tail = circularBuffer->buffer;
	
	return circularBuffer;
}




void circularBufferDel(CircularBuffer *circularBuffer){

	free(circularBuffer);
	
}





void circularBufferAdd(CircularBuffer *cb, int valueToAdd){
	

	while ( (cb->length) <= (cb->size) )  //if the buffer size increase unitl larger then the length, give the error message of buffer is full
		Throw(ERR_BUFFER_IS_FULL);
		
	while (cb->length == NULL)        //if the buffer is empty size, then throw the error buffer is empty
         Throw(ERR_BUFFER_IS_EMPTY);
	
	
	
	*cb->buffer = valueToAdd;  //assign ValueToAdd to buffer
	cb->buffer++; cb->size++;   // buffer and size increament
	
	
	 
	if(cb->size == 0)     //if the size is empty then add value to tail
		*cb->tail = valueToAdd;
		
    if(cb->size !=0)  //if size is not empty then replace the data to the head
        *cb->head = valueToAdd;
     
	else 
		cb->head++;  //increment the head
   
}


int circularBufferRemove(CircularBuffer *cb){


	int PopData;
	
	while (cb->length == 0)        //if the buffer is empty size, then throw the error buffer is empty
         Throw(ERR_BUFFER_IS_EMPTY);
	
	PopData = *cb->tail ;   // assign the data from the buffer tail to PopData

	cb->tail++;  cb->size--;  // increment size and tail
	
	return PopData;
}		
	
 
 
