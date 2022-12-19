.code

FProc proc
movdqu xmm0, [rcx]	;loading 5 pixels to xmm1
;movdqu xmm0, xmm1

;need to extract last pixels to dont interfere next pixels ()
;pextrb eax, xmm0, 12
;pinsrb xmm15, eax, 12
;pextrb eax, xmm0, 13
;pinsrb xmm15, eax, 13
;pextrb eax, xmm0, 14
;pinsrb xmm15, eax, 14

;pextrb eax, xmm0, 15
;pinsrb xmm15, eax, 15
;3 jedna wartosc z konca

;extracting 4 pixels so it will be balanced as all things should be
;xor xmm1, xmm1
pextrb eax, xmm0, 0
pinsrb xmm1, eax, 0
pextrb eax, xmm0, 1
pinsrb xmm1, eax, 1
pextrb eax, xmm0, 2
pinsrb xmm1, eax, 2

pextrb eax, xmm0, 3
pinsrb xmm1, eax, 4
pextrb eax, xmm0, 4
pinsrb xmm1, eax, 5
pextrb eax, xmm0, 5
pinsrb xmm1, eax, 6

pextrb eax, xmm0, 6
pinsrb xmm1, eax, 8
pextrb eax, xmm0, 7
pinsrb xmm1, eax, 9
pextrb eax, xmm0, 8
pinsrb xmm1, eax, 10

pextrb eax, xmm0, 9
pinsrb xmm1, eax, 12
pextrb eax, xmm0, 10
pinsrb xmm1, eax, 13
pextrb eax, xmm0, 11
pinsrb xmm1, eax, 14


;======================================================================
;ladowanie maski pixeli szukanych
movdqu xmm2, [rdx]	;loading color to seek to xmm2
insertps xmm3, xmm2, 00110001b
insertps xmm3, xmm2, 00100000b
insertps xmm3, xmm2, 00010000b
insertps xmm3, xmm2, 00000000b
;======================================================================
;ladowanie maski pixeli do zmiany
movdqu xmm2, [r8]	
insertps xmm4, xmm2, 00110001b
insertps xmm4, xmm2, 00100000b
insertps xmm4, xmm2, 00010000b
insertps xmm4, xmm2, 00000000b

;======================================================================
;comparing and changing
movupd XMM6, XMM1	  ;moving value of first four pixels to XMM4
pcmpeqd  XMM6, XMM3	  ;comparing value of XMM4(Pixels) with XMM2(maskOfColorToChange) in result XMM4 now we have in each 8bajts FFFFFFFF if it match the mask, 00000000 if it didn't
movupd XMM7, XMM6	  ;moving result of comparison to XMM5
andpd XMM6, XMM4	  ;execute logigal AND on XMM4 and XMM3 in result 8bajts colors that match maskOfColorToChange(was FFFFFFFF) was set to color from maskOfColorToSet
andnpd XMM7,XMM1      ;execute logigal NOTAND on XMM5 and XMM0 in result 8bajts colors that not match maskOfColorToChange(was 00000000) was set to color from before(Pixels)
paddq XMM6, XMM7      ;adding both resutls from XMM4 and XMM5 in restult getting 4 pixels with changed corectly colors
movupd XMM1, XMM6     ;moving value of first four pixels back to XMM0
;======================================================================
;making porz¹dek
pextrb eax, xmm1, 0
pinsrb xmm0, eax, 0
pextrb eax, xmm1, 1
pinsrb xmm0, eax, 1
pextrb eax, xmm1, 2
pinsrb xmm0, eax, 2

pextrb eax, xmm1, 4
pinsrb xmm0, eax, 3
pextrb eax, xmm1, 5
pinsrb xmm0, eax, 4
pextrb eax, xmm1, 6
pinsrb xmm0, eax, 5

pextrb eax, xmm1, 8
pinsrb xmm0, eax, 6
pextrb eax, xmm1, 9
pinsrb xmm0, eax, 7
pextrb eax, xmm1, 10
pinsrb xmm0, eax, 8

pextrb eax, xmm1, 12
pinsrb xmm0, eax, 9
pextrb eax, xmm1, 13
pinsrb xmm0, eax, 10
pextrb eax, xmm1, 14
pinsrb xmm0, eax, 11

movdqu [RCX], xmm0
ret
FProc endp

END

;RCX - pixel/e
;RDX - kolor ktory szukamy
;R8 - kolor na ktory zmieniamy