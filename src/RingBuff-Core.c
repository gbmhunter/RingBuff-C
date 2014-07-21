//!
//! @file 				RingBuff-Core.c
//! @author 			Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created 			2012-07-30
//! @last-modified	2014-07-21
//! @brief 				Implements the ring buffer.
//! @details
//!						See README.rst in root dir for more info.

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System includes
#include <stdbool.h>		// bool
#include <stddef.h>		// NULL
#include <stdlib.h>		// calloc(), free()

// User includes
#include "../include/RingBuff-Config.h"
#include "../include/RingBuff-Core.h"

//===============================================================================================//
//================================ PUBLIC METHOD DECLARATIONS ===================================//
//===============================================================================================//

bool RingBuff_Init(ringBuff_t * ringBuff, uint32_t buffSizeBytes)
{
	// Allocate memory for buffer, calloc() also clear the memory, which
	// is what we want
	ringBuff->memPtr = (char *)calloc(buffSizeBytes, sizeof(char));
	
	// Return false is memory allocation failed
	if(ringBuff->memPtr == NULL)
		return false;
	
	// Remember the buffer size
	ringBuff->size = buffSizeBytes;
	
	// Reset head and tail positions
	ringBuff->headPos = 0;
	ringBuff->tailPos = 0;
	
	return true;
}

void RingBuff_Destroy(ringBuff_t * ringBuff)
{
	// Free the memory allocated in RingBuff_Init()
	free(ringBuff->memPtr);
}

uint32_t RingBuff_Read(ringBuff_t * ringBuff, char * buff, uint32_t numBytes)
{
	uint32_t i;
	char* currPos;
	currPos = buff;
	
	for(i = 0; i < numBytes; i++)
	{
		// Make sure tail != head
		// (check if any data is available)
		if(ringBuff->tailPos != ringBuff->headPos)
		{ 		
			// Read one byte from the FIFO buffer
			*currPos++ = ringBuff->memPtr[ringBuff->tailPos];
			
			 // Increment the tail
			ringBuff->tailPos++; 
			
			// Check for wrap-around
			if(ringBuff->tailPos == ringBuff->size)
			{  
				// Reset tail
				ringBuff->tailPos = 0;
			}
		}
		else
		{
			// Return number of bytes read
			return i;  
		}
	}
	
	// All bytes were read
	return numBytes;
}

uint32_t RingBuff_Write(ringBuff_t * ringBuff, const char * buff, uint32_t numBytes)
{
	int i;
	const char * currPos;
	currPos = buff;
	 
	for(i = 0; i < numBytes; i++)
	{
		// Check to see if there is no space left in the buffer
		if((ringBuff->headPos + 1 == ringBuff->tailPos) ||
			((ringBuff->headPos + 1 == ringBuff->size) && (ringBuff->tailPos == 0)))
		{
			// We have run out of space!
			return i; 
		}
		else
		{
			// Write one byte to buffer
			ringBuff->memPtr[ringBuff->headPos] = *currPos++;
			
			// Increment the head
			ringBuff->headPos++;  
			
			// Check for wrap-around
			if(ringBuff->headPos == ringBuff->size)
			{  
				ringBuff->headPos = 0;
			}
		}
	}
	
	// All bytes where written
	return numBytes;
}
	
//===============================================================================================//
//=============================== PRIVATE METHOD DECLARATIONS ===================================//
//===============================================================================================//


// EOF
