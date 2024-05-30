
  /* 2023/2024 
ALSDD TP 2  , TPZ 
By BELGUESMIA OUSSAMA & BELLOUL ZINE EL DINE 
from: 1CP7 */
   LET
       Tmp1 , Tmp2 : LIST OF BST OF ( INTEGER , BOOLEAN ) ;
       N , M , T , Counter1 , Tree_number : INTEGERS ;
       A , Index_l : BST OF ( INTEGER , BOOLEAN ) ;
       Test , Firstelement : BOOLEAN ;
       Checkbst , Left_stop_test , None_stop_test : FUNCTION ( BOOLEAN ) ;
       Randombst , Insertbst , Searchbst , Inorder , Byb_ltr , Byb_rtl , Check_correctness_byb_ltr : ACTION ;
       Leafbyleaf_ltr , Leafbyleaf_rtl , Resettree , Check_correctness_byb_rtl , Checkcorectness_lbl_ltr : ACTION ;
       Checkcorectness_lbl_rtl , Mainmenu , Write_traversal , Check_correctness : ACTION ;
       Result_array : ARRAY ( 50 , 100 ) OF BST OF ( INTEGER , BOOLEAN ) ;
       Trees_array : ARRAY ( 10 ) OF BST OF ( INTEGER , BOOLEAN ) ;
       Copytree : FUNCTION ( BST OF ( INTEGER , BOOLEAN ) ) ;
       Testing_array : ARRAY ( 100 ) OF INTEGER ;
   BEGIN
  /*after lauching the program it will asks for a choice from the MENU 
   remarque:: only one choice need input is the first one asks for tree number (1-10) 
   choice 0 is to exit*/
       Tree_number := 1 ;
       M := 10 ;
       N := 100 ;
       Firstelement := TRUE ;
       Counter1 := 0 ;
       FOR T := 1 , M
           A := NULL ;
           CALL Randombst ( A , N ) ;
           CALL Byb_ltr ( A , Counter1 + 1 ) ;
           CALL Byb_rtl ( A , Counter1 + 2 ) ;
           CALL Leafbyleaf_ltr ( A , Counter1 + 3 ) ;
           CALL Leafbyleaf_rtl ( A , Counter1 + 4 ) ;
           Counter1 := Counter1 + 4 ;
           ASS_ELEMENT ( Trees_array [ T ] , A ) ;
       ENDFOR ;
       CALL Mainmenu ;
   END
  /*Action that create a bst of exactly 'Nn' element*/
   ACTION Randombst ( T , Nn )
   LET
       T : BST OF ( INTEGER , BOOLEAN ) ;
       Nn , H : INTEGER ;
       Test_insert : BOOLEAN ;
   BEGIN
       H := 0 ;
       Test_insert := FALSE ;
       WHILE ( H < Nn )
           CALL Insertbst ( T , RANDNUMBER ( 999 ) + 1 , Test_insert ) ;
           IF ( Test_insert )
               H := H + 1 ;
               Test_insert := FALSE ;
           ENDIF ;
       ENDWHILE ;
   END
  /*Action to insert in bst*/
   ACTION Insertbst ( T , V , B )
   LET
       V : INTEGER ;
       T : BST OF ( INTEGER , BOOLEAN ) ;
       P : BST OF ( INTEGER , BOOLEAN ) ;
       Parentt , Tmp : BST OF ( INTEGER , BOOLEAN ) ;
       B : BOOLEAN ;
       Vv : ( INTEGER , BOOLEAN ) ;
   BEGIN
       B := FALSE ;
       IF ( T = NULL )
           ASS_STRUCT ( Vv , 1 , V ) ;
           ASS_STRUCT ( Vv , 2 , FALSE ) ;
           ALLOCATE_NODE ( Tmp ) ;
           ASS_NODE_VAL ( Tmp , Vv ) ;
           B := TRUE ;
           T := Tmp ;
       ELSE
           CALL Searchbst ( T , V , P , Parentt ) ;
           IF P = NULL
               ASS_STRUCT ( Vv , 1 , V ) ;
               ASS_STRUCT ( Vv , 2 , FALSE ) ;
               ALLOCATE_NODE ( Tmp ) ;
               ASS_NODE_VAL ( Tmp , Vv ) ;
               B := TRUE ;
               IF STRUCT ( NODE_VALUE ( Parentt ) , 1 ) < V
                   ASS_RC ( Parentt , Tmp )
               ELSE
                   ASS_LC ( Parentt , Tmp )
               ENDIF ;
           ELSE
               B := FALSE ;
           ENDIF ;
       ENDIF ;
   END
  /*an action to serash fo value in bst and return the node with the value and its parent 
   if res=null then the value doesn't exist in the tree*/
   ACTION Searchbst ( T , V , Res , Parentt )
   LET
       T : BST OF ( INTEGER , BOOLEAN ) ;
       V : INTEGER ;
       Res , Parentt , P , Q : BST OF ( INTEGER , BOOLEAN ) ;
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
               IF STRUCT ( NODE_VALUE ( P ) , 1 ) = V
                   Found := TRUE ;
               ELSE
                   Q := P ;
                   IF STRUCT ( NODE_VALUE ( P ) , 1 ) < V
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
       T , P : BST OF ( INTEGER , BOOLEAN ) ;
       S : STACK OF BST OF ( INTEGER , BOOLEAN ) ;
       Stop : BOOLEAN ;
   BEGIN
       Stop := FALSE ;
       P := T ;
       CREATESTACK ( S ) ;
       WHILE NOT Stop
           WHILE P # NULL
               PUSH ( S , P ) ;
               P := LC ( P ) ;
           ENDWHILE ;
           IF NOT EMPTY_STACK ( S )
               POP ( S , P ) ;
               WRITE ( STRUCT ( NODE_VALUE ( P ) , 1 ) ) ;
               P := RC ( P ) ;
           ELSE
               Stop := TRUE ;
           ENDIF ;
       ENDWHILE ;
       WRITE ( '=======' ) ;
   END
  /*function checks if bst is builded correctly using inorder traversal and returns a boolean 
   which is true if and only if each element is inferior than its next inorder and returns the number of elements*/
   FUNCTION Checkbst ( T , N_elements ) : BOOLEAN
   LET
       N_elements : INTEGER ;
       T : BST OF ( INTEGER , BOOLEAN ) ;
       P , Q : BST OF ( INTEGER , BOOLEAN ) ;
       S : STACK OF BST OF ( INTEGER , BOOLEAN ) ;
       Stop , Testb : BOOLEAN ;
   BEGIN
       N_elements := 0 ;
       Stop := FALSE ;
       P := T ;
       Testb := TRUE ;
       Q := NULL ;
       WHILE ( NOT Stop )
           WHILE P # NULL
               PUSH ( S , P ) ;
               IF LC ( P ) # NULL
               ENDIF ;
               P := LC ( P ) ;
           ENDWHILE ;
           IF NOT EMPTY_STACK ( S )
               POP ( S , P ) ;
               N_elements := N_elements + 1 ;
               IF Q <> NULL
              /*Compare Q with its next inorder P 'if p<=q return false*/
                   IF STRUCT ( NODE_VALUE ( Q ) , 1 ) >= STRUCT ( NODE_VALUE ( P ) , 1 )
                       Testb := FALSE ;
                   ENDIF ;
               ENDIF ;
               Q := P ;
               P := RC ( P ) ;
           ELSE
               Stop := TRUE ;
           ENDIF ;
       ENDWHILE ;
       Checkbst := Testb ;
       WRITE ( N_elements ) ;
   END
  /*action to peform branch by branch  from left to right */
   ACTION Byb_ltr ( Byb_tr , Ltr_number )
   LET
       Byb_tr : BST OF ( INTEGER , BOOLEAN ) ;
       Next_branch , Current_branch : STACK OF BST OF ( INTEGER , BOOLEAN ) ;
       A : BST OF ( INTEGER , BOOLEAN ) ;
       Stop : BOOLEAN ;
       Ltr_index , Ltr_number : INTEGER ;
   BEGIN
       Ltr_index := 1 ;
       IF Byb_tr # NULL
           Stop := FALSE ;
           A := Byb_tr ;
          /*stack to save non visited right branches to visit it after the left branch*/
           CREATESTACK ( Next_branch ) ;
          /*stack contains the branch */
           CREATESTACK ( Current_branch ) ;
           WHILE ( NOT Stop )
               WHILE ( A # NULL )
              /*decend to the leftmost leaf and push branch nodes*/
                   PUSH ( Current_branch , A ) ;
                   IF RC ( A ) # NULL
                  /*if the element has no LC and it is not a leaf we continue to right*/
                       IF LC ( A ) = NULL
                           A := RC ( A ) ;
                       ELSE
                      /*save right non visited node*/
                           PUSH ( Next_branch , RC ( A ) ) ;
                           A := LC ( A ) ;
                       ENDIF ;
                   ELSE
                       A := LC ( A ) ;
                   ENDIF ;
               ENDWHILE ;
               WHILE ( NOT EMPTY_STACK ( Current_branch ) )
              /*pop branch elements and save them to result array*/
                   POP ( Current_branch , A ) ;
                   ASS_ELEMENT ( Result_array [ Ltr_number , Ltr_index ] , A ) ;
                   Ltr_index := Ltr_index + 1 ;
               ENDWHILE ;
               IF NOT EMPTY_STACK ( Next_branch )
              /*visit right branches*/
                   POP ( Next_branch , A ) ;
               ELSE
                   Stop := TRUE ;
               ENDIF
           ENDWHILE ;
       ENDIF ;
   END
  /*action to peform branch by branch  from right to left */
   ACTION Byb_rtl ( Byb_tr , Rtl_number )
   LET
       Byb_tr : BST OF ( INTEGER , BOOLEAN ) ;
       Next_branch , Current_branch : STACK OF BST OF ( INTEGER , BOOLEAN ) ;
       A : BST OF ( INTEGER , BOOLEAN ) ;
       Stop , Found : BOOLEAN ;
       Rtl_index , Rtl_number : INTEGER ;
   BEGIN
       Rtl_index := 1 ;
       IF Byb_tr # NULL
           Stop := FALSE ;
           A := Byb_tr ;
          /*stack to save non visited right branches to visit it after the right branch*/
           CREATESTACK ( Next_branch ) ;
          /*stack contains the branch */
           CREATESTACK ( Current_branch ) ;
           WHILE ( NOT Stop )
               WHILE ( A # NULL )
                   PUSH ( Current_branch , A ) ;
                  /*decend to the rightmost leaf and push branch nodes*/
                   IF LC ( A ) # NULL
                  /*if the element has no RC and it is not a leaf we continue to left*/
                       IF RC ( A ) = NULL
                           A := LC ( A ) ;
                       ELSE
                      /*save left non visited node*/
                           PUSH ( Next_branch , LC ( A ) ) ;
                           A := RC ( A ) ;
                       ENDIF ;
                   ELSE
                       A := RC ( A ) ;
                   ENDIF ;
               ENDWHILE ;
              /*pop branch elements and save them to result array*/
               WHILE ( NOT EMPTY_STACK ( Current_branch ) )
                   POP ( Current_branch , A ) ;
                   ASS_ELEMENT ( Result_array [ Rtl_number , Rtl_index ] , A ) ;
                   Rtl_index := Rtl_index + 1 ;
               ENDWHILE ;
              /*visit left branches*/
               IF NOT EMPTY_STACK ( Next_branch )
                   POP ( Next_branch , A ) ;
               ELSE
                   Stop := TRUE ;
               ENDIF
           ENDWHILE ;
       ENDIF ;
   END
  /*Action checks the correctness of bransh by bransh from left to right traversal 
by saving all branches from left to right in a linked list then delete duplicates*/
   ACTION Check_correctness_byb_ltr ( Tr ) ;
   LET
       Tr , P , K : BST OF ( INTEGER , BOOLEAN ) ;
       Brancheslist , L , Q : LIST OF BST OF ( INTEGER , BOOLEAN ) ;
       V , V2 : INTEGER ;
       Leafsqueue : QUEUE OF INTEGER ;
       S : STACK OF BST OF ( INTEGER , BOOLEAN ) ;
       First , Stop , Found : BOOLEAN ;
       H_tab : ARRAY ( 1000 ) OF BOOLEAN ;
   BEGIN
       K := NULL ;
       P := Tr ;
       CREATESTACK ( S ) ;
       CREATEQUEUE ( Leafsqueue ) ;
       Stop := FALSE ;
       First := TRUE ;
      /*we collect all leafs values from left to right in a queue 'leafsqueue*/
       WHILE ( NOT Stop )
      /*we desed to the left most leaf and add it to the queue*/
           WHILE ( P # NULL )
               K := P ;
              /*if there is a branch in the right side we save its path to get the leaf there*/
               IF ( RC ( P ) # NULL )
                   PUSH ( S , RC ( P ) ) ;
               ENDIF ;
               P := LC ( P ) ;
           ENDWHILE ;
           IF RC ( K ) = NULL
               ENQUEUE ( Leafsqueue , STRUCT ( NODE_VALUE ( K ) , 1 ) ) ;
           ENDIF ;
           IF ( NOT EMPTY_STACK ( S ) )
               POP ( S , P ) ;
           ELSE
               Stop := TRUE ;
           ENDIF ;
       ENDWHILE ;
      /*we know that all branches are a path from root to a leaf so if we use a search similar algorithm 
to go from the root to a leaf we have a branche and we save it stack to save in the linked list from bottom to top 
++ number of paths=number of leafs*/
       L := NULL ;
       WHILE ( NOT EMPTY_QUEUE ( Leafsqueue ) )
      /*we dequeue leaf by leaf from left to write*/
           DEQUEUE ( Leafsqueue , V ) ;
           P := Tr ;
           WHILE ( P # NULL )
          /*using search similar algorith we save the path to the leaf*/
               PUSH ( S , P ) ;
               IF ( STRUCT ( NODE_VALUE ( P ) , 1 ) = V )
                   P := NULL ;
               ELSE
                   IF ( V > STRUCT ( NODE_VALUE ( P ) , 1 ) )
                       P := RC ( P ) ;
                   ELSE
                       P := LC ( P ) ;
                   ENDIF ;
               ENDIF ;
           ENDWHILE ;
          /*we save the branch in the linked list*/
           WHILE ( NOT EMPTY_STACK ( S ) )
               POP ( S , P ) ;
               ALLOCATE_CELL ( L ) ;
               ASS_VAL ( L , P ) ;
               IF ( First )
                   Brancheslist := L ;
                   Q := L ;
                   First := FALSE ;
               ELSE
                   ASS_ADR ( Q , L ) ;
                   Q := L ;
               ENDIF ;
           ENDWHILE ;
       ENDWHILE ;
      /*we use a hash table to delete duplicates from the linked list in efficient way 
where the index of value N  is N 
'in our test values are between 1 and 1000' and it can be exeeded by extending the hash table size*/
      /*we initialise all values as false in the hash table (which means not inserted)*/
       FOR V := 1 , 1000
           ASS_ELEMENT ( H_tab [ V ] , FALSE )
       ENDFOR ;
       V := 1 ;
       L := Brancheslist ;
       Q := NULL ;
       WHILE ( L # NULL )
           V2 := STRUCT ( NODE_VALUE ( CELL_VALUE ( L ) ) , 1 ) ;
          /*we check if the value is inserted or not using the hash table*/
           IF ( ELEMENT ( H_tab [ V2 ] ) = FALSE )
               ASS_ELEMENT ( Testing_array [ V ] , V2 ) ;
               V := V + 1 ;
              /*after inserting an element we set its emplacement to true in the hash table*/
               ASS_ELEMENT ( H_tab [ V2 ] , TRUE ) ;
           ENDIF ;
           Q := L ;
           L := NEXT ( L ) ;
           FREE ( Q ) ;
          /* free the cell we alredy treat */
       ENDWHILE ;
   END
  /*Action checks the correctness of bransh by bransh from right to left traversal 
we used same algorithm for (from left to right) traversal by just replacing the leafsqueue by a stack 
so we have the leafs ordred from right to left and do the same process in the mentioned algorithm*/
   ACTION Check_correctness_byb_rtl ( Tr ) ;
   LET
       Tr , P , K : BST OF ( INTEGER , BOOLEAN ) ;
       Brancheslist , L , Q : LIST OF BST OF ( INTEGER , BOOLEAN ) ;
       V , V2 : INTEGER ;
       Leafsstack : STACK OF INTEGER ;
       S : STACK OF BST OF ( INTEGER , BOOLEAN ) ;
       First , Stop , Found : BOOLEAN ;
       H_tab : ARRAY ( 1000 ) OF BOOLEAN ;
   BEGIN
       K := NULL ;
       P := Tr ;
       CREATESTACK ( S ) ;
       CREATESTACK ( Leafsstack ) ;
       Stop := FALSE ;
       First := TRUE ;
       WHILE ( NOT Stop )
           WHILE ( P # NULL )
               K := P ;
               IF ( RC ( P ) # NULL )
                   PUSH ( S , RC ( P ) ) ;
               ENDIF ;
               P := LC ( P ) ;
           ENDWHILE ;
           IF RC ( K ) = NULL
               PUSH ( Leafsstack , STRUCT ( NODE_VALUE ( K ) , 1 ) ) ;
           ENDIF ;
           IF ( NOT EMPTY_STACK ( S ) )
               POP ( S , P ) ;
           ELSE
               Stop := TRUE ;
           ENDIF ;
       ENDWHILE ;
       L := NULL ;
       WHILE ( NOT EMPTY_STACK ( Leafsstack ) )
           POP ( Leafsstack , V ) ;
           P := Tr ;
           WHILE ( P # NULL )
               PUSH ( S , P ) ;
               IF ( STRUCT ( NODE_VALUE ( P ) , 1 ) = V )
                   P := NULL ;
               ELSE
                   IF ( V > STRUCT ( NODE_VALUE ( P ) , 1 ) )
                       P := RC ( P ) ;
                   ELSE
                       P := LC ( P ) ;
                   ENDIF ;
               ENDIF ;
           ENDWHILE ;
           WHILE ( NOT EMPTY_STACK ( S ) )
               POP ( S , P ) ;
               ALLOCATE_CELL ( L ) ;
               ASS_VAL ( L , P ) ;
               IF ( First )
                   Brancheslist := L ;
                   Q := L ;
                   First := FALSE ;
               ELSE
                   ASS_ADR ( Q , L ) ;
                   Q := L ;
               ENDIF ;
           ENDWHILE ;
       ENDWHILE ;
       FOR V := 1 , 1000
           ASS_ELEMENT ( H_tab [ V ] , FALSE )
       ENDFOR ;
       V := 1 ;
       L := Brancheslist ;
       Q := NULL ;
       WHILE ( L # NULL )
           V2 := STRUCT ( NODE_VALUE ( CELL_VALUE ( L ) ) , 1 ) ;
           IF ( ELEMENT ( H_tab [ V2 ] ) = FALSE )
               ASS_ELEMENT ( Testing_array [ V ] , V2 ) ;
               V := V + 1 ;
               ASS_ELEMENT ( H_tab [ V2 ] , TRUE ) ;
           ENDIF ;
           Q := L ;
           L := NEXT ( L ) ;
           FREE ( Q ) ;
          /* free the cell we already treat*/
       ENDWHILE ;
   END
  /*Action do the leafs first from left to write traversl and save result in result_array*/
   ACTION Leafbyleaf_ltr ( Root , Index1 )
   LET
       P , K , Root : BST OF ( INTEGER , BOOLEAN ) ;
       S : STACK OF BST OF ( INTEGER , BOOLEAN ) ;
       Stop , Found : BOOLEAN ;
       Index , Index1 : INTEGER ;
   BEGIN
  /*set all tree nodes visited field to false*/
       CALL Resettree ( Root ) ;
       K := NULL ;
       Index := 1 ;
       P := Root ;
      /*stack to save right childs to visit right branches after done with left one*/
       CREATESTACK ( S ) ;
       Stop := FALSE ;
       WHILE ( NOT Stop )
           WHILE ( NOT Left_stop_test ( P ) )
               K := P ;
               IF ( None_stop_test ( RC ( P ) ) )
              /*Push RC of P if it is not null and not visited*/
                   PUSH ( S , RC ( P ) ) ;
               ENDIF ;
               P := LC ( P ) ;
           ENDWHILE ;
           IF NOT None_stop_test ( RC ( K ) )
          /*thanks to the loop we know that LC(k) is null or visited, then if RC(k) is visited or null 
           k is the next element to visit we add it to the result queue and mark it as visited*/
               IF ( Index1 <= 40 )
                   ASS_ELEMENT ( Result_array [ Index1 , Index ] , K ) ;
               ENDIF ;
               Index := Index + 1 ;
               ASS_STRUCT ( NODE_VALUE ( K ) , 2 , TRUE ) ;
           ENDIF ;
           IF ( NOT EMPTY_STACK ( S ) )
          /*visited the right bransh*/
               POP ( S , P ) ;
           ELSE
               IF ( K = Root )
              /*last element to visit is the root if it is treated we exit the loop*/
                   Stop := TRUE ;
               ELSE
              /*re-visit the tree after set all visited nodes 'visited filed to true*/
                   P := Root ;
               ENDIF ;
           ENDIF ;
       ENDWHILE ;
   END
  /*Action do the leafs first from right to left traversl and save result in result_array*/
   ACTION Leafbyleaf_rtl ( Root , Lbl_ltr_index )
   LET
       P , K , Root : BST OF ( INTEGER , BOOLEAN ) ;
       S : STACK OF BST OF ( INTEGER , BOOLEAN ) ;
       Stop , Found : BOOLEAN ;
       Index , Lbl_ltr_index : INTEGER ;
   BEGIN
  /*set all tree nodes visited field to false*/
       CALL Resettree ( Root ) ;
       K := NULL ;
       Index := 1 ;
       P := Root ;
      /*stack to save left childs to visit left branches after done with right one*/
       CREATESTACK ( S ) ;
       Stop := FALSE ;
       WHILE ( NOT Stop )
           WHILE ( NOT Left_stop_test ( P ) )
               K := P ;
              /*Push LC of P if it is not null and not visited*/
               IF ( None_stop_test ( LC ( P ) ) )
                   PUSH ( S , LC ( P ) ) ;
               ENDIF ;
               P := RC ( P ) ;
           ENDWHILE ;
          /*thanks to the loop we know that RC(k) is null or visited, then if LC(k) is visited or null 
           k is the next element to visit we add it to the result queue and mark it as visited*/
           IF NOT None_stop_test ( LC ( K ) )
               ASS_ELEMENT ( Result_array [ Lbl_ltr_index , Index ] , K ) ;
               Index := Index + 1 ;
               ASS_STRUCT ( NODE_VALUE ( K ) , 2 , TRUE ) ;
           ENDIF ;
           IF ( NOT EMPTY_STACK ( S ) )
          /*visited the left bransh*/
               POP ( S , P ) ;
           ELSE
               IF ( K = Root )
              /*last element to visit is the root if it is treated we exit the loop*/
                   Stop := TRUE ;
               ELSE
              /*re-visit the tree after set all visited nodes 'visited filed to true*/
                   P := Root ;
               ENDIF ;
           ENDIF ;
       ENDWHILE ;
   END
  /*a function return a boolean which is true if and only if the enter parameter is visited or null*/
   FUNCTION Left_stop_test ( Leaf_noud1 ) : BOOLEAN
   LET
       Leaf_noud1 : BST OF ( INTEGER , BOOLEAN ) ;
       Leaf_test : BOOLEAN ;
   BEGIN
       Leaf_test := FALSE ;
       IF ( Leaf_noud1 = NULL )
           Leaf_test := TRUE ;
       ELSE
           IF ( STRUCT ( NODE_VALUE ( Leaf_noud1 ) , 2 ) )
               Leaf_test := TRUE ;
           ENDIF ;
       ENDIF ;
       Left_stop_test := Leaf_test ;
   END
  /*a function return a boolean which is true if and only if the enter parameter (node) is not null and not visited*/
   FUNCTION None_stop_test ( Leaf_noud2 ) : BOOLEAN
   LET
       Leaf_noud2 : BST OF ( INTEGER , BOOLEAN ) ;
       Leaf_test2 : BOOLEAN ;
   BEGIN
       Leaf_test2 := FALSE ;
       IF ( Leaf_noud2 # NULL )
           IF ( NOT STRUCT ( NODE_VALUE ( Leaf_noud2 ) , 2 ) )
               Leaf_test2 := TRUE ;
           ENDIF ;
       ENDIF ;
       None_stop_test := Leaf_test2 ;
   END
  /*Action visite all the nodes of the tree (inorder) and reset all 'visited' field to false*/
   ACTION Resettree ( T )
   LET
       T , P : BST OF ( INTEGER , BOOLEAN ) ;
       S : STACK OF BST OF ( INTEGER , BOOLEAN ) ;
       Stop : BOOLEAN ;
   BEGIN
       Stop := FALSE ;
       P := T ;
       CREATESTACK ( S ) ;
       WHILE NOT Stop
           WHILE P # NULL
               PUSH ( S , P ) ;
               P := LC ( P ) ;
           ENDWHILE ;
           IF NOT EMPTY_STACK ( S )
               POP ( S , P ) ;
               ASS_STRUCT ( NODE_VALUE ( P ) , 2 , FALSE ) ;
               P := RC ( P ) ;
           ELSE
               Stop := TRUE ;
           ENDIF ;
       ENDWHILE ;
   END
   FUNCTION Copytree ( Copytr ) : BST OF ( INTEGER , BOOLEAN ) ;
   LET
       Copytr , Newroot : BST OF ( INTEGER , BOOLEAN ) ;
       Vv : ( INTEGER , BOOLEAN ) ;
   BEGIN
       IF ( Copytr = NULL )
           Copytree := NULL ;
       ELSE
           ALLOCATE_NODE ( Newroot ) ;
           ASS_STRUCT ( Vv , 1 , STRUCT ( NODE_VALUE ( Copytr ) , 1 ) ) ;
           ASS_STRUCT ( Vv , 2 , FALSE ) ;
           ASS_NODE_VAL ( Newroot , Vv ) ;
           ASS_LC ( Newroot , Copytree ( LC ( Copytr ) ) ) ;
           ASS_RC ( Newroot , Copytree ( RC ( Copytr ) ) ) ;
           Copytree := Newroot ;
       ENDIF ;
   END
  /* Verify the leafs traversal first from left to write */
   ACTION Checkcorectness_lbl_ltr ( Root )
   LET
       P , K , Lbl_ltr_root , Root , Gp : BST OF ( INTEGER , BOOLEAN ) ;
       S , Parent_s : STACK OF BST OF ( INTEGER , BOOLEAN ) ;
       Stop , Found , First : BOOLEAN ;
       Index : INTEGER ;
   BEGIN
       Index := 1 ;
       First := TRUE ;
      /*Make a copy of the tree before doing the test beacause we need to delete all the nodes*/
       Lbl_ltr_root := Copytree ( Root ) ;
       K := NULL ;
       P := Lbl_ltr_root ;
       CREATESTACK ( S ) ;
      /*A stack containing the right childs when decending to the left side to visit the righ bransh after*/
       CREATESTACK ( Parent_s ) ;
      /*A stack containing the parent to have access to it when pop from stack S*/
       Stop := FALSE ;
       WHILE ( NOT Stop )
           WHILE ( P # NULL )
               Gp := K ;
               K := P ;
               IF ( RC ( P ) # NULL )
              /*save the right child and its parent to visit the right branch after done with left one*/
                   PUSH ( Parent_s , P ) ;
                   PUSH ( S , RC ( P ) ) ;
               ENDIF ;
               P := LC ( P ) ;
           ENDWHILE ;
          /*Thanks to the loop we know that lc(k)=p=null then if rc(k)=null, k is a leaf*/
           IF RC ( K ) = NULL
               ASS_ELEMENT ( Testing_array [ Index ] , STRUCT ( NODE_VALUE ( K ) , 1 ) ) ;
              /*add the element to result array*/
               Index := Index + 1 ;
               IF ( Gp # NULL )
              /*if the parent is not null we update the parent child field pointing to K to null then free K*/
                   IF ( K = RC ( Gp ) )
                       ASS_RC ( Gp , NULL ) ;
                   ELSE
                       ASS_LC ( Gp , NULL ) ;
                   ENDIF ;
               ENDIF ;
               FREE_NODE ( K ) ;
           ENDIF ;
           IF ( NOT EMPTY_STACK ( S ) )
          /*visit the right bransh*/
               POP ( S , P ) ;
               POP ( Parent_s , K ) ;
           ELSE
               IF ( K = Lbl_ltr_root )
              /*last element to visit is the root if it is treated we exit the loop*/
                   Stop := TRUE ;
               ELSE
              /*we re-visit the tree after deleting visited leaves*/
                   P := Lbl_ltr_root ;
                   K := NULL ;
               ENDIF ;
           ENDIF ;
       ENDWHILE ;
   END
  /* Verify the leafs traversal first from right to left */
   ACTION Checkcorectness_lbl_rtl ( Root )
   LET
       P , K , Lbl_ltr_root , Root , Gp : BST OF ( INTEGER , BOOLEAN ) ;
       S , Parent_s : STACK OF BST OF ( INTEGER , BOOLEAN ) ;
       Stop , Found , First : BOOLEAN ;
       Index : INTEGER ;
   BEGIN
       Index := 1 ;
       First := TRUE ;
      /*Make a copy of the tree before doing the test beacause we need to delete all the nodes*/
       Lbl_ltr_root := Copytree ( Root ) ;
       K := NULL ;
       P := Lbl_ltr_root ;
       CREATESTACK ( S ) ;
      /*A stack containing the right childs when decending to the left side to visit the left bransh after*/
       CREATESTACK ( Parent_s ) ;
      /*A stack containing the parent to have access to it when pop from stack S*/
       Stop := FALSE ;
       WHILE ( NOT Stop )
           WHILE ( P # NULL )
               Gp := K ;
               K := P ;
               IF ( LC ( P ) # NULL )
              /*save the left child and its parent to visit the left branch after done with right one*/
                   PUSH ( Parent_s , P ) ;
                   PUSH ( S , LC ( P ) ) ;
               ENDIF ;
               P := RC ( P ) ;
           ENDWHILE ;
          /*Thanks to the loop we know that rc(k)=p=null then if lc(k)=null, k is a leaf*/
           IF LC ( K ) = NULL
               ASS_ELEMENT ( Testing_array [ Index ] , STRUCT ( NODE_VALUE ( K ) , 1 ) ) ;
              /*add the element to result array*/
               Index := Index + 1 ;
               IF ( Gp # NULL )
              /*if the parent is not null we update the parent child field pointing to K to null then free K*/
                   IF ( K = RC ( Gp ) )
                       ASS_RC ( Gp , NULL ) ;
                   ELSE
                       ASS_LC ( Gp , NULL ) ;
                   ENDIF ;
               ENDIF ;
               FREE_NODE ( K ) ;
           ENDIF ;
           IF ( NOT EMPTY_STACK ( S ) )
          /*visit the left bransh*/
               POP ( S , P ) ;
               POP ( Parent_s , K ) ;
           ELSE
               IF ( K = Lbl_ltr_root )
              /*last element to visit is the root if it is treated we exit the loop*/
                   Stop := TRUE ;
               ELSE
              /*we re-visit the tree after deleting visited leaves*/
                   P := Lbl_ltr_root ;
                   K := NULL ;
               ENDIF ;
           ENDIF ;
       ENDWHILE ;
   END
   ACTION Write_traversal ( Index )
   LET
       Index , Index1 : INTEGER ;
   BEGIN
       WRITE ( 'the traversal result:' ) ;
       FOR Index1 := 1 , 100
           WRITE ( STRUCT ( NODE_VALUE ( ELEMENT ( Result_array [ Index , Index1 ] ) ) , 1 ) ) ;
       ENDFOR ;
   END
   ACTION Check_correctness ( Index )
   LET
       Check_result : BOOLEAN ;
       Index , V , Index1 : INTEGER ;
   BEGIN
       Check_result := TRUE ;
       Index_l := ELEMENT ( Trees_array [ Tree_number ] ) ;
       IF ( Index = 1 )
           WRITE ( 'The traversal result:' ) ;
           CALL Write_traversal ( ( ( Tree_number - 1 ) * 4 ) + 1 ) ;
           CALL Check_correctness_byb_ltr ( Index_l ) ;
           WRITE ( 'Check traversal result:' ) ;
           FOR Index1 := 1 , 100
               WRITE ( ELEMENT ( Testing_array [ Index1 ] ) ) ;
               V := STRUCT ( NODE_VALUE ( ELEMENT ( Result_array [ ( ( Tree_number - 1 ) * 4 ) + 1 , Index1 ] ) ) , 1 ) ;
               IF ( ( ELEMENT ( Testing_array [ Index1 ] ) ) # V )
                   Check_result := FALSE ;
               ENDIF ;
           ENDFOR ;
           WRITE ( 'Check result: ' , Check_result ) ;
       ELSE
           IF ( Index = 2 )
               WRITE ( 'The traversal result:' ) ;
               CALL Write_traversal ( ( ( Tree_number - 1 ) * 4 ) + 2 ) ;
               CALL Check_correctness_byb_rtl ( Index_l ) ;
               WRITE ( 'Check traversal result:' ) ;
               FOR Index1 := 1 , 100
                   WRITE ( ELEMENT ( Testing_array [ Index1 ] ) ) ;
                   V := STRUCT ( NODE_VALUE ( ELEMENT ( Result_array [ ( ( Tree_number - 1 ) * 4 ) + 2 , Index1 ] ) ) , 1 )
                   ;
                   IF ( ( ELEMENT ( Testing_array [ Index1 ] ) ) # V )
                       Check_result := FALSE ;
                   ENDIF ;
               ENDFOR ;
               WRITE ( 'Check result: ' , Check_result ) ;
           ELSE
               IF ( Index = 3 )
                   WRITE ( 'The traversal result:' ) ;
                   CALL Write_traversal ( ( ( Tree_number - 1 ) * 4 ) + 3 ) ;
                   CALL Checkcorectness_lbl_ltr ( Index_l ) ;
                   WRITE ( 'Check traversal result:' ) ;
                   FOR Index1 := 1 , 100
                       WRITE ( ELEMENT ( Testing_array [ Index1 ] ) ) ;
                       V := STRUCT ( NODE_VALUE ( ELEMENT ( Result_array [ ( ( Tree_number - 1 ) * 4 ) + 3 , Index1 ] ) ) ,
                       1 ) ;
                       IF ( ( ELEMENT ( Testing_array [ Index1 ] ) ) # V )
                           Check_result := FALSE ;
                       ENDIF ;
                   ENDFOR ;
                   WRITE ( 'Check result: ' , Check_result ) ;
               ELSE
                   IF ( Index = 4 )
                       WRITE ( 'The traversal result:' ) ;
                       CALL Write_traversal ( ( ( Tree_number - 1 ) * 4 ) + 4 ) ;
                       CALL Checkcorectness_lbl_rtl ( Index_l ) ;
                       WRITE ( 'Check traversal result:' ) ;
                       FOR Index1 := 1 , 100
                           WRITE ( ELEMENT ( Testing_array [ Index1 ] ) ) ;
                           V := STRUCT ( NODE_VALUE ( ELEMENT ( Result_array [ ( ( Tree_number - 1 ) * 4 ) + 4 , Index1 ] )
                           ) , 1 ) ;
                           IF ( ( ELEMENT ( Testing_array [ Index1 ] ) ) # V )
                               Check_result := FALSE ;
                           ENDIF ;
                       ENDFOR ;
                       WRITE ( 'Check result: ' , Check_result ) ;
                   ENDIF ;
               ENDIF ;
           ENDIF ;
       ENDIF ;
   END
   ACTION Mainmenu
   LET
       Choice : INTEGER ;
       Exit : BOOLEAN ;
   BEGIN
       Exit := FALSE ;
       WHILE ( NOT Exit )
           WRITE ( '=== ALSDD TP2 (Z) By  ===' ) ;
           WRITE ( 'BELGUESMIA OUSSAMA & BELLOUL WASSIM ZINE El DINE' ) ;
           WRITE ( '==============================================================================' ) ;
           WRITE ( 'The program has created 10 BST of 100 random value' ) ;
           WRITE ( 'You can perform the following tasks' ) ;
           WRITE ( '  1. choose a tree (1-10)' ) ;
           WRITE ( '  2. check the tree correctness' ) ;
           WRITE ( '  3. travers the tree branch by branch from bottom to top  & from left to right' ) ;
           WRITE ( '  4. travers the tree branch by branch from bottom to top & from right to left' ) ;
           WRITE ( '  5. traverse the tree leaf by leaf from left right' ) ;
           WRITE ( '  6. traverse the tree leaf by leaf from right to left' ) ;
           WRITE ( '  7. check the corectness of the 1st traversal' ) ;
           WRITE ( '  8. check the corectness of the 2nd traversal' ) ;
           WRITE ( '  9. check the corectness of the 3rd traversal' ) ;
           WRITE ( ' 10. check the corectness of the 4th traversal' ) ;
           WRITE ( ' 0. EXIT..' ) ;
           READ ( Choice ) ;
           IF ( Choice = 1 )
               READ ( Tree_number ) ;
               WHILE ( Tree_number < 1 ) OR ( Tree_number > 10 )
                   READ ( Tree_number ) ;
               ENDWHILE ;
           ELSE
               IF ( Choice = 2 )
                   Index_l := ELEMENT ( Trees_array [ Tree_number ] ) ;
                   WRITE ( 'You chose option 2: check the tree correctness' ) ;
                   Test := Checkbst ( Index_l , Counter1 ) ;
                   WRITE ( 'You are treating tree number: ' , Tree_number ) ;
                   WRITE ( 'The tree has: ' , Counter1 , ' element' ) ;
                   WRITE ( 'The check result is ' , Test ) ;
                   WRITE ( 'Traversal inorder:' ) ;
                   CALL Inorder ( Index_l ) ;
               ELSE
                   IF ( Choice = 3 )
                       WRITE ( 'You chose travers the tree branch by branch from bottom to top&from left to right' )
                       ;
                       CALL Write_traversal ( ( ( Tree_number - 1 ) * 4 ) + 1 ) ;
                   ELSE
                       IF ( Choice = 4 )
       WRITE ('You chose option 4: travers the tree branch by branch from bottom to top & from right to left') ;
                           CALL Write_traversal ( ( ( Tree_number - 1 ) * 4 ) + 2 ) ;
                       ELSE
                           IF ( Choice = 5 )
                               WRITE ( 'You chose option 5: traverse the tree leaf by leaf from left right' ) ;
                               CALL Write_traversal ( ( ( Tree_number - 1 ) * 4 ) + 3 ) ;
                           ELSE
                               IF ( Choice = 6 )
                                   WRITE ( 'You chose option 6: traverse the tree leaf by leaf from right to left' )
                                   ;
                                   CALL Write_traversal ( ( ( Tree_number - 1 ) * 4 ) + 4 ) ;
                               ELSE
                                   IF ( Choice = 7 )
                                       WRITE ( 'You chose option 7: check the corectness of the 1st traversal' ) ;
                                       CALL Check_correctness ( 1 ) ;
                                   ELSE
                                       IF ( Choice = 8 )
                                           WRITE ( 'You chose option 8: check the corectness of the 2nd traversal' )
                                           ;
                                           CALL Check_correctness ( 2 ) ;
                                       ELSE
                                           IF ( Choice = 9 )
                                               WRITE (
                                               'You chose option 9: check the corectness of the 3rd traversal' ) ;
                                               CALL Check_correctness ( 3 ) ;
                                           ELSE
                                               IF ( Choice = 10 )
                                                   WRITE (
                                                   'You chose option 10: check the corectness of the 4th traversal' )
                                                   ;
                                                   CALL Check_correctness ( 4 ) ;
                                               ELSE
                                                   Exit := TRUE ;
                                               ENDIF
                                           ENDIF
                                       ENDIF
                                   ENDIF
                               ENDIF
                           ENDIF
                       ENDIF
                   ENDIF
               ENDIF
           ENDIF ;
       ENDWHILE ;
       WRITE ( 'Exiting program.....' ) ;
   END
