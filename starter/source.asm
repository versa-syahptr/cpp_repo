
00000000 <_main>:
   0:	55                   	push   %ebp
   1:	89 e5                	mov    %esp,%ebp
   3:	83 e4 f0             	and    $0xfffffff0,%esp
   6:	83 ec 10             	sub    $0x10,%esp
   9:	e8 00 00 00 00       	call   e <_main+0xe>
   e:	c7 44 24 0c 0a 00 00 	movl   $0xa,0xc(%esp)
  15:	00 
  16:	c7 44 24 0c 05 00 00 	movl   $0x5,0xc(%esp)
  1d:	00 
  1e:	b8 00 00 00 00       	mov    $0x0,%eax
  23:	c9                   	leave  
  24:	c3                   	ret    
  25:	90                   	nop
  26:	90                   	nop
  27:	90                   	nop
