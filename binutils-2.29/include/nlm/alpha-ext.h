/* Alpha NLM (NetWare Loadable Module) support for BFD.
   Copyright (C) 1993-2017 Free Software Foundation, Inc.
   By Ian Lance Taylor, Cygnus Support

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

/* An Alpha NLM starts with an instance of this structure.  */

struct nlm32_alpha_external_prefix_header
{
  /* Magic number.  Must be NLM32_ALPHA_MAGIC.  */
  unsigned char magic[4];
  /* Format descriptor.  Current value is 2.  */
  unsigned char format[4];
  /* Size of prefix header.  */
  unsigned char size[4];
  /* Padding.  */
  unsigned char pad1[4];
  /* More fields may be added later, supposedly.  */
};

/* The external format of an Alpha NLM reloc.  This is the same as an
   Alpha ECOFF reloc.  */

struct nlm32_alpha_external_reloc
{
  unsigned char r_vaddr[8];
  unsigned char r_symndx[4];
  unsigned char r_bits[4];
};

/* Constants to unpack the r_bits field of a reloc.  */

#define RELOC_BITS0_TYPE_LITTLE			0xff
#define RELOC_BITS0_TYPE_SH_LITTLE		0

#define RELOC_BITS1_EXTERN_LITTLE		0x01

#define RELOC_BITS1_OFFSET_LITTLE		0x7e
#define RELOC_BITS1_OFFSET_SH_LITTLE		1

#define RELOC_BITS1_RESERVED_LITTLE		0x80
#define RELOC_BITS1_RESERVED_SH_LITTLE		7
#define RELOC_BITS2_RESERVED_LITTLE		0xff
#define RELOC_BITS2_RESERVED_SH_LEFT_LITTLE	1
#define RELOC_BITS3_RESERVED_LITTLE		0x03
#define RELOC_BITS3_RESERVED_SH_LEFT_LITTLE	9

#define RELOC_BITS3_SIZE_LITTLE			0xfc
#define RELOC_BITS3_SIZE_SH_LITTLE		2

/* The external format of the fixed header.  */

typedef struct nlm32_alpha_external_fixed_header
{

  /* The signature field identifies the file as an NLM.  It must contain
     the signature string, which depends upon the NLM target. */

  unsigned char signature[24];

  /* The version of the header.  At this time, the highest version number
     is 4. */

  unsigned char version[4];

  /* The name of the module, which must be a DOS name (1-8 characters followed
     by a period and a 1-3 character extension).  The first byte is the byte
     length of the name and the last byte is a null terminator byte.  This
     field is fixed length, and any unused bytes should be null bytes.  The
     value is set by the OUTPUT keyword to NLMLINK. */

  unsigned char moduleName[14];

  /* Padding to make it come out correct. */

  unsigned char pad1[2];

  /* The byte offset of the code image from the start of the file. */

  unsigned char codeImageOffset[4];

  /* The size of the code image, in bytes. */

  unsigned char codeImageSize[4];

  /* The byte offset of the data image from the start of the file. */

  unsigned char dataImageOffset[4];

  /* The size of the data image, in bytes. */

  unsigned char dataImageSize[4];

  /* The size of the uninitialized data region that the loader is to be
     allocated at load time.  Uninitialized data follows the initialized
     data in the NLM address space. */

  unsigned char uninitializedDataSize[4];

  /* The byte offset of the custom data from the start of the file.  The
     custom data is set by the CUSTOM keyword to NLMLINK.  It is possible
     for this to be EOF if there is no custom data. */

  unsigned char customDataOffset[4];

  /* The size of the custom data, in bytes. */

  unsigned char customDataSize[4];

  /* The byte offset of the module dependencies from the start of the file.
     The module dependencies are determined by the MODULE keyword in
     NLMLINK. */

  unsigned char moduleDependencyOffset[4];

  /* The number of module dependencies at the moduleDependencyOffset. */

  unsigned char numberOfModuleDependencies[4];

  /* The byte offset of the relocation fixup data from the start of the file */
     
  unsigned char relocationFixupOffset[4];

  unsigned char numberOfRelocationFixups[4];

  unsigned char externalReferencesOffset[4];

  unsigned char numberOfExternalReferences[4];

  unsigned char publicsOffset[4];

  unsigned char numberOfPublics[4];

  /* The byte offset of the internal debug info from the start of the file.
     It is possible for this to be EOF if there is no debug info. */

  unsigned char debugInfoOffset[4];

  unsigned char numberOfDebugRecords[4];

  unsigned char codeStartOffset[4];

  unsigned char exitProcedureOffset[4];

  unsigned char checkUnloadProcedureOffset[4];

  unsigned char moduleType[4];

  unsigned char flags[4];

} Nlm32_alpha_External_Fixed_Header;
