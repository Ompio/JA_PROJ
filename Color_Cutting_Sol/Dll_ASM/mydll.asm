.code

FProc proc
movdqu xmm1, [rcx] ;loading 5 pixels to xmm1
movdqu xmm2, [rdx] ;loading color to seek to xmm2

movdqu xmm3, [r8]  ;loading color change to xmm3


ret
FProc endp

END

;RCX - pixel/e
;RDX - kolor ktory szukamy
;R8 - kolor na ktory zmieniamy