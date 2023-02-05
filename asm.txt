.code

FProc proc

;ladowanie maski do uporzadkowania danych
mov eax,00000000111111111111111111111111b
pinsrd xmm9, eax, 0
pinsrd xmm9, eax, 1
pinsrd xmm9, eax, 2
pinsrd xmm9, eax, 3



;porzadkowanie danych aby mieć je w formacie 0PPP 0PPP 0PPP 0PPP P-jedna składowa rgb
mov eax, [rcx]+9
mov r11d, eax
pinsrd xmm1, eax, 3
mov eax, [rcx]+6
pinsrd xmm1, eax, 2
mov eax, [rcx]+3
pinsrd xmm1, eax, 1
mov eax, [rcx]
pinsrd xmm1, eax, 0

andpd xmm1, xmm9 ;operacja logiczna usuwająca pixele w miejscach gdzie chcemy mieć 0

extractps eax,xmm1,3
sub r11d,eax ;odejmowanie od najmłodszych danych dane które będziemy przetwarzać (robimy to aby później zapisać najmłodsze dane)
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
movupd xmm6, xmm1     ;przeniesienie wartości 4 pixeli do XMM6
pcmpeqd  xmm6, xmm3   ;porównywanie wartości XMM6(pixele) z XMM3(maską kolorów szukanych) w wyniku XMM6 mamy w każdych 8bajtach FFFFFFFF jeśli się zgadza z maską i 00000000 jeśli nie
movupd xmm7, xmm6     ;przeniesienie wyniku porównania do XMM7
andpd xmm6, xmm4      ;logiczny and na XMM6 i XMM4 w rezultacie 8bajtów kolorów których wartości były zgodne z maską z XMM3 są zamieniane na wartości z maski kolorów do zmiany XMM4
andnpd xmm7,xmm1      ;logiczny nand na XMM7 i XMM1 w rezultacie 8bajtów kolorów których wartości nie były zgodne z maską z XMM3 są zamieniane na wartości kolorów pochodzących z obrazu(XMM1)
paddq xmm6, xmm7      ;dodawanie XMM6 i XMM7 dzięki czemu mamy połączone wartości pikseli nowych i starych
movupd xmm1, xmm6     ;zwracamy wartość pixeli do XMM1 w celu późniejszego zapisania do pamięci
;======================================================================
;porzadkowanie danych i zwracanie do pamieci

extractps eax,xmm1,0
mov [rcx],eax
extractps eax,xmm1,1
mov [rcx]+3,eax
extractps eax,xmm1,2
mov [rcx]+6,eax
extractps eax,xmm1,3
add eax,r11d ;przyracamy najmlodsze dane aby zachowac ich wartosc (w innym przypadku byla by 00)
mov [rcx]+9,eax

ret
FProc endp

END

;RCX - pixel/e
;RDX - kolor ktory szukamy
;R8 - kolor na ktory zmieniamy