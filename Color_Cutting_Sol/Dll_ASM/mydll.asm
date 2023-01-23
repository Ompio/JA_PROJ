.code

FProc proc
;movdqu xmm0, [rcx] ;loading 5 pixels to xmm1
;movdqu xmm0, xmm1

;3 jedna wartosc z konca

;making mask
mov eax,00000000111111111111111111111111b
pinsrd xmm9, eax, 0
pinsrd xmm9, eax, 1
pinsrd xmm9, eax, 2
pinsrd xmm9, eax, 3

;extracting 4 pixels so it will be balanced as all things should be
;xor xmm1, xmm1



mov eax, [rcx]+9
mov r11d, eax
pinsrd xmm1, eax, 3
mov eax, [rcx]+6
pinsrd xmm1, eax, 2
mov eax, [rcx]+3
pinsrd xmm1, eax, 1
mov eax, [rcx]
pinsrd xmm1, eax, 0

andpd xmm1, xmm9

extractps eax,xmm1,3
sub r11d,eax ;odejmowanie
;======================================================================
;ladowanie maski pixeli szukanych
movdqu xmm2, [rdx]  ;loading color to seek to xmm2
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
movupd xmm6, xmm1     ;moving value of first four pixels to XMM4
pcmpeqd  xmm6, xmm3   ;comparing value of XMM6(Pixels) with XMM3(maskOfColorToChange) in result XMM6 now we have in each 8bajts FFFFFFFF if it match the mask, 00000000 if it didn't
movupd xmm7, xmm6     ;moving result of comparison to XMM7
andpd xmm6, xmm4      ;execute logigal AND on XMM6 and XMM4 in result 8bajts colors that match maskOfColorToChange(was FFFFFFFF) was set to color from maskOfColorToSet
andnpd xmm7,xmm1      ;execute logigal NOTAND on XMM7 and XMM1 in result 8bajts colors that not match maskOfColorToChange(was 00000000) was set to color from before(Pixels)
paddq xmm6, xmm7      ;adding both resutls from XMM6 and XMM7 in restult getting 4 pixels with changed corectly colors
movupd xmm1, xmm6     ;moving value of first four pixels back to XMM1
;======================================================================
;making porz¹dek

extractps eax,xmm1,0
mov [rcx],eax
extractps eax,xmm1,1
mov [rcx]+3,eax
extractps eax,xmm1,2
mov [rcx]+6,eax
extractps eax,xmm1,3
add eax,r11d
mov [rcx]+9,eax

;xor edi,edi

;movdqu [RCX], xmm0
ret
FProc endp

END

;RCX - pixel/e
;RDX - kolor ktory szukamy
;R8 - kolor na ktory zmieniamy