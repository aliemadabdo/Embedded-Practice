/* linker script Cortex-M3 
 * By: Ali Emad */

MEMORY
{
flash(RX): ORIGIN = 0x08000000, LENGTH = 128K
sram(RWX): ORIGIN = 0x02000000, LENGTH = 20K
}

SECTIONS
{
	.text : { /* take all vector starting with key word vector*/
		*(.vectors*)
		*(.text)
		*(.rodata)
		_E_text = . ;
	}> flash

	.data : {
		_S_DATA = . ;
		*(.data)
		. = ALIGN(4) ;
		_E_DATA = . ;
	}> sram AT>flash /* >VMA AT>LMA    AT: At loading */
	
	.bss : {
		_S_BSS = . ;
		*(.bss)
		_E_BSS = . ;
	}> sram /* always in ram */
}
