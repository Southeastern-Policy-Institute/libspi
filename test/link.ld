OUTPUT_FORMAT(pei-i386)
SECTIONS
{
  . = SIZEOF_HEADERS;
  . = ALIGN(__section_alignment__);
  .text  __image_base__ + ( __section_alignment__ < 0x1000 ? . : __section_alignment__ ) :
  {
    KEEP(*(.init))
    *(.text)
    *(SORT(.text$*))
    ___CTOR_LIST__ = .; __CTOR_LIST__ = . ;
    LONG (-1);*(.ctors); *(.ctor); *(SORT(.ctors.*));  LONG (0);
    ___DTOR_LIST__ = .; __DTOR_LIST__ = . ;
    LONG (-1); *(.dtors); *(.dtor); *(SORT(.dtors.*));  LONG (0);
    KEEP (*(.fini))
