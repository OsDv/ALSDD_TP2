
   LET
       Listhead : LIST OF BST ;
       P , Q : LIST OF BST ;
       N , M , I , T : INTEGERS ;
       A , B , C , D : BST ;
       Checkbst : FUNCTION ( BOOLEAN ) ;
       Randombst , Insertbst , Searchbst , Inorder , Byb_ltr : ACTION ;
   BEGIN
       M := 10 ;
       N := 100 ;
       P := NULL ;
       Q := NULL ;
      /*       ALLOCATE_CELL ( P ) ; 
       CALL Randombst ( A , N ) ; 
       ASS_VAL ( P , A ) ; 
       WRITE ( T ) ; 
       WRITE ( Checkbst ( A ) ) ; 
       Listhead := P ; 
       FOR T := 2 , M 
           ALLOCATE_CELL ( Q ) ; 
           CALL Randombst ( A , N ) ; 
           ASS_VAL ( Q , A ) ; 
           ASS_ADR ( P , Q ) ; 
           P := Q ; 
           Q := NULL ; 
           WRITE ( T ) ; 
           WRITE ( Checkbst ( A ) ) ; 
       ENDFOR ; */
       CREATE_BST ( A , [ 45 , 20 , 10 , 35 , 65 , 55 , 85 , 50 , 58 , 75 , 95 , 56 , 60 , 90 , 98 , 57 , 62 , 88 ] ) ;
       CALL Byb_ltr ( A ) ;
   END
   ACTION Randombst ( T , N )
   LET
       T : BST ;
       N : INTEGER ;
   BEGIN
       FOR I := 1 , N
           CALL Insertbst ( T , RANDNUMBER ( 999 ) ) ;
       ENDFOR ;
   END
   ACTION Insertbst ( T , V )
   LET
       V : INTEGER ;
       T : BST ;
       P : BST ;
       Parentt , Tmp : BST ;
   BEGIN
       ALLOCATE_NODE ( Tmp ) ;
       ASS_NODE_VAL ( Tmp , V ) ;
       IF ( T = NULL )
           T := Tmp ;
       ELSE
           CALL Searchbst ( T , V , P , Parentt ) ;
           IF P = NULL
               IF NODE_VALUE ( Parentt ) < V
                   ASS_RC ( Parentt , Tmp )
               ELSE
                   ASS_LC ( Parentt , Tmp )
               ENDIF
           ENDIF
       ENDIF
   END
   ACTION Searchbst ( T , V , Res , Parentt )
   LET
       T : POINTER TO BST ;
       V : INTEGER ;
       Res , Parentt , P , Q : POINTER TO BST ;
       Found : BOOLEAN ;
   BEGIN
       IF T = NULL
           Res := NULL ;
           Parentt := NULL ;
       ELSE
           Q := NULL ;
           P := T ;
           Found := FALSE ;
           WHILE ( P <> NULL ) AND ( NOT Found )
               IF NODE_VALUE ( P ) = V
                   Found := TRUE ;
               ELSE
                   Q := P ;
                   IF NODE_VALUE ( P ) < V
                       P := RC ( P ) ;
                   ELSE
                       P := LC ( P ) ;
                   ENDIF
               ENDIF
           ENDWHILE ;
           Res := P ;
           Parentt := Q ;
       ENDIF
   END
   ACTION Inorder ( T )
   LET
       T , P : POINTER TO BST ;
       S : STACK OF BST ;
       Stop : BOOLEAN ;
   BEGIN
       Stop := FALSE ;
       P := T ;
       WHILE NOT Stop
           WHILE P # NULL
               PUSH ( S , P ) ;
               P := LC ( P ) ;
           ENDWHILE ;
           IF NOT EMPTY_STACK ( S )
               POP ( S , P ) ;
               WRITE ( NODE_VALUE ( P ) ) ;
               P := RC ( P ) ;
           ELSE
               Stop := TRUE ;
           ENDIF ;
       ENDWHILE
   END
   FUNCTION Checkbst ( T ) : BOOLEAN
   LET
       T : BST ;
       P , Q : POINTER TO BST ;
       S : STACK OF BST ;
       Stop : BOOLEAN ;
   BEGIN
       Stop := FALSE ;
       P := T ;
       WHILE NOT Stop
           WHILE P # NULL
               PUSH ( S , P ) ;
               IF LC ( P ) # NULL
                   Q := P ;
               ENDIF ;
               P := LC ( P ) ;
           ENDWHILE ;
           IF NOT EMPTY_STACK ( S )
               POP ( S , P ) ;
               IF Q <= P
                   Checkbst := FALSE ;
               ENDIF ;
               P := RC ( P ) ;
           ELSE
               Stop := TRUE ;
           ENDIF ;
       ENDWHILE ;
       Checkbst := TRUE ;
   END
   ACTION Byb_ltr ( Byb_tr )
   LET
       Byb_tr : BST ;
       R_s , L_s : STACK OF BST ;
       A : BST ;
       Stop : BOOLEAN ;
   BEGIN
       IF Byb_tr # NULL
           Stop := FALSE ;
           A := Byb_tr ;
           CREATESTACK ( R_s ) ;
           CREATESTACK ( L_s ) ;
           WHILE ( NOT Stop )
               WHILE ( A # NULL )
                   PUSH ( L_s , A ) ;
                   if rc(A)#null
                      if lc(A)=null
                         push(L_s,rc(A));
                         a:=rc(a);
                      else
                          push(R_s,rc(A));
                      endif;
                   endif;
                   A := LC ( A ) ;
               ENDWHILE ;
               WHILE ( NOT EMPTY_STACK ( L_s ) )
                   POP ( L_s , A ) ;
                   WRITE ( NODE_VALUE ( A ) ) ;
               ENDWHILE ;
               IF NOT EMPTY_STACK ( R_s )
                   POP ( R_s , A ) ;
               ELSE
                   Stop := TRUE ;
               ENDIF
           ENDWHILE ;
       ENDIF ;
   END
