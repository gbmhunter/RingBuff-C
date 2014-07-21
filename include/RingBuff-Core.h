//!
//! @file 				RingBuff-Core.h
//! @author 			Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created 			2012-07-30
//! @last-modified	2014-07-21
//! @brief 				Implements the ring buffer.
//! @details
//!						See README.rst in root dir for more info.

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef RING_BUFF_H
#define RING_BUFF_H

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

#include <stdint.h>

#include "RingBuff-Config.h"

typedef struct 	
{	
		//! @brief		Pointer to allocated memory space for buffer.
		char* memPtr;
		
		//! @brief		The size of the buffer (in bytes). Set by Buffer().
		uint32_t size;
		
		//! @brief		The head position, measured in bytes from the start of the buffer (bufPtr).
		uint32_t headPos;
		
		//! @brief		The tail position, measured in bytes from the start of the buffer (bufPtr).
		uint32_t tailPos;
	
} ringBuff_t;

//===============================================================================================//
//================================= PUBLIC FUNCTION DECLARATIONS ================================//
//===============================================================================================//

//! @brief		Initialises and allocates memory for the buffer, ready for use.
//! @returns	True if initialisation was successful (memory allocation worked), otherwise false.
//! @public
bool RingBuff_Init(ringBuff_t * ringBuff, uint32_t buffSizeBytes);

//! @brief		Deallocates all memory and destroys FIFO buffer.
//! @param		ringBuff		RingBuff buffer to destroy. Must have been initialised
//!								first with RingBuff_Init(), otherwise behaviour is undefined.
void RingBuff_Destroy(ringBuff_t * ringBuff);

//! @brief		Reads up to a number of bytes from the FIFO buffer.
//! @details	Will read numBytes of data, unless there is not enough data to read, in which case
//!				returns early.
//! @param		ringBuff			RingBuff buffer object to read from.
//! @param		buff				Buffer to read to.
//! @param		numBytes			Maximum number of bytes to read.
//! @returns	Number of bytes read (which could be from 0 to numBytes).
//! @public
uint32_t RingBuff_Read(ringBuff_t * ringBuff, char * buff, uint32_t numBytes);

//! @brief		Writes a number of bytes to the FIFO buffer.
//! @details	Will return early if there is no more space left in the buffer. Does
//!				not write over contents.
//! @param		ringBuff			RingBuff buffer object to write to.
//! @param		buff				Buffer to write from.
//! @param		numBytes			Maximum number of bytes to write.
//! @returns	Number of bytes written (which could be from 0 to numBytes).
//! @public
uint32_t RingBuff_Write(ringBuff_t * ringBuff, const char * buff, uint32_t numBytes);

#endif // #ifndef RING_BUFF_H

// EOF
