# minilibx

수정사항

### /* minilibx_macos */

/ Makefile /  
Origin   
8	CFLAGS+=-O2  
Fix  
8	CFLAGS+=-O2 -Wno-deprecated-declarations  

### /* minilibx_mms_20191025_beta */

/ interface.swift /  
Origin  
248	CGAssociateMouseAndMouseCursorPosition(UInt32(1))  
Fix  
248	CGAssociateMouseAndMouseCursorPosition(boolean_t(1))  

/ mlx_init.swift /  
Origin  
43	loopParam = UnsafeMutableRawPointer(&inLoop)  /// dummy addr init  
Fix  
43	loopParam = UnsafeMutableRawPointer(bitPattern:1)! /// set to 1-1  
44	loopParam -= 1  

/ mlx_window.swift /  
Origin  
22	for _ in 0...31  
23	{  
24		eventFuncts.append(Optional.none)  
25		eventParams.append(UnsafeMutableRawPointer(&keyrepeat)) /// dummy address here, null not needed  
26	}  
Fix  
22	var ptr = UnsafeMutableRawPointer(bitPattern:1)!  
23	ptr -= 1  
24	for _ in 0...31  
25 {  
26		eventFuncts.append(Optional.none)  
27		eventParams.append(ptr)  
28	}  

### /* minilibx_mms_20210621 */  

/ interface.swift /  
Origin  
273	CGAssociateMouseAndMouseCursorPosition(UInt32(1))  
Fix  
273	CGAssociateMouseAndMouseCursorPosition(boolean_t(1))  
