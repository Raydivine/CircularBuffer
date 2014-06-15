#include <stdio.h>
#include "CircularBuffer.h"
#include <malloc.h>
#include "CircularBuffer.h"
#include "CException.h"


CircularBuffer *circularBufferNew(int length) {
	CircularBuffer *circularBuffer;

	circularBuffer = malloc(sizeof(CircularBuffer));
	circularBuffer->buffer = malloc(sizeof(int) * length);
	circularBuffer->length = length;
	circularBuffer->size = 0;
	circularBuffer->head = circularBuffer->buffer;
	circularBuffer->tail = circularBuffer->buffer;
	
	return circularBuffer;
}


void circularBufferDel(CircularBuffer *circularBuffer) {
	free(circularBuffer);
}

void circularBufferAdd(CircularBuffer *cb, int valueToAdd) {

	
    if (cb == NULL || cb->length == NULL) //if the buffer is empty size, then throw the error buffer is empty
         Throw(ERR_BUFFER_IS_EMPTY);

     *cb->tail = valueToAdd; // add the value to the buffer tail
      cb->tail++;
	  
    if (cb->tail == cb->buffer)   //if the valueToadd add until the tail end
   {
       Throw(ERR_BUFFER_IS_FULL); // throw the buffer is full message
	   *cb->head = valueToAdd;  // put the valueToAdd to the head , then start add again
        cb->head++;}

	Throw(ERR_NO_ERROR);			
}
	
int circularBufferRemove(CircularBuffer *cb){

    if (cb == NULL || cb->buffer == NULL)  //if the buffer is empty size, then throw the error buffer is empty
         Throw(ERR_BUFFER_IS_EMPTY);

    int RemoveData = *cb->head; //Assign the buufer head data to variable RemoveData, if there is rest continue add 
    cb->head++;
	
    if (cb->head == Cb->buffer_end) //when the head is assifn until end of buffer , throw the error message of buffer is empty
	     Throw(ERR_BUFFER_IS_EMPTY);
  
  return RemoveData; // return all the data

}		
	
 
 