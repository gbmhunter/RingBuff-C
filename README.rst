==========
RingBuff-C
==========

---------------------------------------------------------------
A C ring buffer designed for embedded applications.
---------------------------------------------------------------

- Author: gbmhunter <gbmhunter@gmail.com> (http://www.cladlab.com)
- Created: 2014/07/21
- Last Modified: 2014/07/21
- Version: v1.0.0.0
- Company: CladLabs
- Project: n/a
- Language: C
- Compiler: GCC	
- uC Model: n/a
- Computer Architecture: n/a
- Operating System: n/a
- Documentation Format: Doxygen
- License: GPLv3

Description
===========

Designed to be both powerful, efficient and portable in an embedded (microcontroller) environment.

Uses the cyclic head/tail method to implement the ring buffer. The head is where data is currently being written to, while the tail is where data is currently being read from.

Typically, one task/interrupt will write to the buffer, while another will read from the buffer.

External Dependencies
=====================

Nothing here yet...

Issues
======

See GitHub Issues.

Usage
=====

Nothing here yet...
	
Changelog
=========

======== ========== ===================================================================================================
Version  Date       Comment
======== ========== ===================================================================================================
v1.0.0.0 2014/07/21 Initial commit. Copy of the RingBuff-Cpp repository, which has been ported from C++ to C.
======== ========== ===================================================================================================