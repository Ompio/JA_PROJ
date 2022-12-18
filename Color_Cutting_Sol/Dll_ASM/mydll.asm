.code

FProc proc
movdqu xmm1, [rcx]	;loading 5 pixels to xmm1
movdqu xmm0, xmm1

;need to extract last pixels to dont interfere next pixels ()
;3 jedna wartosc z konca

;extracting 4 pixels so it will be balanced as all things should be
pextrb eax, xmm0, 0
pinsrb xmm3, eax, 0
pextrb eax, xmm0, 1
pinsrb xmm3, eax, 1
pextrb eax, xmm0, 2
pinsrb xmm3, eax, 2

pextrb eax, xmm0, 3
pinsrb xmm3, eax, 4
pextrb eax, xmm0, 4
pinsrb xmm3, eax, 5
pextrb eax, xmm0, 5
pinsrb xmm3, eax, 6

pextrb eax, xmm0, 6
pinsrb xmm3, eax, 8
pextrb eax, xmm0, 7
pinsrb xmm3, eax, 9
pextrb eax, xmm0, 8
pinsrb xmm3, eax, 10

pextrb eax, xmm0, 9
pinsrb xmm3, eax, 10
pextrb eax, xmm0, 10
pinsrb xmm3, eax, 11
pextrb eax, xmm0, 11
pinsrb xmm3, eax, 12




;movd rax, xmm0
;and rax, 0000000000ffffffh
;pinsrd xmm3, eax , 0
;movd rax, xmm0
;and rax, 0000ffffff000000h

movdqu xmm2, [rdx]	;loading color to seek to xmm2
insertps xmm3, xmm2, 00110001b
insertps xmm3, xmm2, 00100000b
insertps xmm3, xmm2, 00010000b
insertps xmm3, xmm2, 00000000b
mov eax, 14
pinsrb xmm4, eax, 12

movdqu xmm3, [r8]	;loading color change to xmm3
					;shuffle do przerzucania danych z xmm3 do xmm1



ret
FProc endp

END

;RCX - pixel/e
;RDX - kolor ktory szukamy
;R8 - kolor na ktory zmieniamy