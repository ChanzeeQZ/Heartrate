*version 6.3 1092401604
u 728
U? 63
V? 12
R? 11
I? 4
? 8
C? 3
D? 2
@libraries
@analysis
.AC 0 3 0
+0 101
+1 100
+2 10meg
.TRAN 1 0 0 0
+0 20ns
+1 1000us
@targets
@attributes
@translators
a 0 u 13 0 0 0 hln 100 PSPICE=PSPICE
a 0 u 13 0 0 0 hln 100 PCBOARDS=PCB
a 0 u 13 0 0 0 hln 100 CADSTAR=PCB
a 0 u 13 0 0 0 hln 100 EDIF=PCB
a 0 u 13 0 0 0 hln 100 ORCAD=PCB
a 0 u 13 0 0 0 hln 100 PADS=PCB
a 0 u 13 0 0 0 hln 100 PCAD=PCB
a 0 u 13 0 0 0 hln 100 TANGO=PCB
a 0 u 13 0 0 0 hln 100 SCICARDS=PCB
a 0 u 13 0 0 0 hln 100 POLARIS=PCB
@index
pageloc 1 0 4953 
@status
n 0 97:05:25:14:34:24;867274464 e 
s 0 97:05:25:14:34:28;867274468 e 
c 97:05:25:14:36:41;867274601
*page 1 0 970 720 iA
@ports
port 11 AGND 720 360 h
port 12 AGND 550 100 u
port 236 AGND 600 390 h
port 330 AGND 550 490 h
port 509 AGND 170 400 h
port 726 AGND 370 490 h
port 727 AGND 450 490 h
@parts
part 3 VDC 550 150 u
a 1 u 13 0 -11 18 hcn 100 DC=15V
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 x 0 0 0 0 hln 100 PKGREF=V+
a 1 xp 9 0 -12 31 hcn 100 REFDES=V+
part 41 r 720 350 v
a 0 u 13 0 3 -1 hln 100 VALUE=10k
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 x 0 0 0 0 hln 100 PKGREF=RL
a 0 x 0 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0 0 0 0 hln 100 GATE=
a 0 xp 9 0 15 0 hln 100 REFDES=RL
part 329 VDC 550 480 u
a 1 u 13 0 -11 18 hcn 100 DC=15V
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 x 0 0 0 0 hln 100 PKGREF=V-
a 1 xp 9 0 -12 31 hcn 100 REFDES=V-
part 580 IDC 170 360 u
a 1 u 13 0 45 29 hcn 100 DC=1000nA
a 0 sp 11 0 38 48 hln 100 PART=IDC
a 0 x 0 0 0 0 hln 100 PKGREF=SIG
a 1 xp 9 0 46 12 hcn 100 REFDES=SIG
part 588 VPULSE 370 430 h
a 1 u 0 0 0 0 hcn 100 DC=0
a 1 u 0 0 0 0 hcn 100 AC=0
a 1 u 0 0 0 0 hcn 100 V1=4
a 1 u 0 0 0 0 hcn 100 V2=0
a 1 u 0 0 0 0 hcn 100 TD=20u
a 1 u 0 0 0 0 hcn 100 TR=200n
a 1 u 0 0 0 0 hcn 100 TF=200n
a 1 u 0 0 0 0 hcn 100 PW=400u
a 1 u 0 0 0 0 hcn 100 PER=490u
a 0 x 0 0 0 0 hln 100 PKGREF=S1
a 1 xp 9 0 20 10 hcn 100 REFDES=S1
part 589 VPULSE 450 430 h
a 1 u 0 0 0 0 hcn 100 DC=0
a 1 u 0 0 0 0 hcn 100 AC=0
a 1 u 0 0 0 0 hcn 100 V1=4
a 1 u 0 0 0 0 hcn 100 V2=0
a 1 u 0 0 0 0 hcn 100 TD=0u
a 1 u 0 0 0 0 hcn 100 TR=200n
a 1 u 0 0 0 0 hcn 100 TF=200n
a 1 u 0 0 0 0 hcn 100 PW=10u
a 1 u 0 0 0 0 hcn 100 PER=490u
a 0 x 0 0 0 0 hln 100 PKGREF=S2
a 1 xp 9 0 20 10 hcn 100 REFDES=S2
part 652 D1N4148 240 330 d
a 0 sp 11 0 -29 29 hln 100 PART=D1N4148
a 0 a 0 0 0 0 hln 100 PKGREF=D1
a 0 s 0 0 0 0 hln 100 PKGTYPE=
a 0 ap 9 0 -9 28 hln 100 refdes=D1
part 587 IVC102M 330 220 h
a 0 s 11 0 230 164 hln 100 PART=IVC102M
a 0 x 0 0 0 0 hln 100 PKGREF=U1
a 0 x 0 0 0 0 hln 100 PKGTYPE=
a 0 xp 9 0 14 -6 hln 100 REFDES=U1
part 667 r 210 370 v
a 0 u 13 0 7 1 hln 100 VALUE=1E8
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 x 0 0 0 0 hln 100 PKGREF=RD
a 0 x 0 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0 0 0 0 hln 100 GATE=
a 0 xp 9 0 23 0 hln 100 REFDES=RD
part 674 C 280 340 v
a 0 u 13 0 1 7 hln 100 VALUE=50pF
a 0 sp 0 0 0 10 hlb 100 PART=C
a 0 x 0 0 0 0 hln 100 PKGREF=CD
a 0 x 0 0 0 0 hln 100 PKGTYPE=CK05
a 0 s 0 0 0 0 hln 100 GATE=
a 0 xp 9 0 15 0 hln 100 REFDES=CD
part 0 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PageSize=A
a 1 s 13 0 180 60 hcn 100 PageTitle=
a 1 s 13 0 300 95 hrn 100 PageNO=1
a 1 s 13 0 340 95 hrn 100 PageCount=1
part 83 nodeMarker 720 300 h
a 0 a 0 0 4 22 hlb 100 LABEL=3
@conn
w 494
s 550 190 550 150 493
w 496
s 550 100 550 110 495
w 502
s 550 370 550 440 633
w 565
s 720 300 720 310 564
s 620 300 720 300 566
w 569
s 720 350 720 360 568
w 598
s 370 370 370 430 635
w 600
s 450 370 450 430 636
w 602
s 410 190 410 160 601
s 410 160 440 160 603
s 440 160 440 190 605
s 440 160 470 160 659
s 500 160 500 190 661
s 470 160 500 160 665
s 470 190 470 160 663
w 619
s 550 490 550 480 618
w 678
s 170 320 170 310 699
s 240 310 280 310 710
s 240 330 240 310 705
s 240 310 210 310 713
s 210 310 170 310 716
s 210 330 210 310 711
s 280 310 330 310 714
w 681
s 280 390 280 340 680
s 280 390 240 390 688
s 240 360 240 390 690
s 170 400 170 390 684
s 170 390 170 360 695
s 240 390 210 390 693
s 210 390 170 390 698
s 210 370 210 390 696
s 330 340 310 340 717
s 310 340 310 390 719
s 310 390 280 390 721
w 723
s 600 390 600 370 570
w 724
s 370 470 370 490 620
w 725
s 450 470 450 490 626
@junction
j 550 110
+ p 3 -
+ w 496
j 550 100
+ s 12
+ w 496
j 550 150
+ p 3 +
+ w 494
j 720 310
+ p 41 2
+ w 565
j 720 300
+ p 83 pin1
+ w 565
j 720 350
+ p 41 1
+ w 569
j 720 360
+ s 11
+ w 569
j 440 160
+ w 602
+ w 602
j 550 480
+ p 329 +
+ w 619
j 550 490
+ s 330
+ w 619
j 370 470
+ p 588 -
+ w 724
j 450 470
+ p 589 -
+ w 725
j 370 430
+ p 588 +
+ w 598
j 450 430
+ p 589 +
+ w 600
j 550 440
+ p 329 -
+ w 502
j 550 190
+ p 587 V+
+ w 494
j 550 370
+ p 587 V-
+ w 502
j 600 370
+ p 587 DGND
+ w 723
j 620 300
+ p 587 OUT
+ w 565
j 330 310
+ p 587 IN
+ w 678
j 370 370
+ p 587 S1
+ w 598
j 450 370
+ p 587 S2
+ w 600
j 440 190
+ p 587 C1
+ w 602
j 410 190
+ p 587 INM
+ w 602
j 500 190
+ p 587 C3
+ w 602
j 470 190
+ p 587 C2
+ w 602
j 470 160
+ w 602
+ w 602
j 280 340
+ p 674 1
+ w 681
j 170 400
+ s 509
+ w 681
j 170 360
+ p 580 +
+ w 681
j 240 360
+ p 652 2
+ w 681
j 240 390
+ w 681
+ w 681
j 170 390
+ w 681
+ w 681
j 210 370
+ p 667 1
+ w 681
j 210 390
+ w 681
+ w 681
j 170 320
+ p 580 -
+ w 678
j 280 310
+ p 674 2
+ w 678
j 240 330
+ p 652 1
+ w 678
j 210 330
+ p 667 2
+ w 678
j 240 310
+ w 678
+ w 678
j 210 310
+ w 678
+ w 678
j 330 340
+ p 587 AGND
+ w 681
j 280 390
+ w 681
+ w 681
j 600 390
+ s 236
+ w 723
j 370 490
+ s 726
+ w 724
j 450 490
+ s 727
+ w 725
@attributes
a 0 s 0 0 0 0 hln 100 PAGETITLE=
a 0 s 0 0 0 0 hln 100 PAGENO=1
a 0 s 0 0 0 0 hln 100 PAGESIZE=A
a 0 s 0 0 0 0 hln 100 PAGECOUNT=1
@text
s 5 170 280 hln 100 Photodiode Model
