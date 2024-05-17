LET
    root, leftChild, rightChild, leftLeftChild : POINTER TO NODE;
    queue : QUEUE;

BEGIN
    /* Create nodes and initialize tree */
    CALL ALLOCATE_NODE(root)
    CALL ALLOCATE_NODE(leftChild)
    CALL ALLOCATE_NODE(rightChild)
    CALL ALLOCATE_NODE(leftLeftChild)

    root.data := 1;
    CALL ASS_LC(root, leftChild)
    CALL ASS_RC(root, rightChild)
    root.visited := FALSE

    leftChild.data := 2;
    CALL ASS_LC(leftChild, leftLeftChild)
    leftChild.right := NULL
    leftChild.visited := FALSE

    rightChild.data := 3;
    rightChild.left := NULL
    rightChild.right := NULL
    rightChild.visited := FALSE

    leftLeftChild.data := 4;
    leftLeftChild.left := NULL
    leftLeftChild.right := NULL
    leftLeftChild.visited := FALSE

    /* Call Traversal2 to print nodes in leaf-by-leaf order */
    CALL Traversal2(root)
END

ACTION LeafbyLeaf (queue, root)
LET
    queue : QUEUE;
    root : POINTER TO NODE;
BEGIN
    IF root = NULL OR root.visited = TRUE :
        RETURN
    ENDIF

    IF (root.left = NULL OR root.left.visited = TRUE) AND (root.right = NULL OR root.right.visited = TRUE) :
        CALL ENQUEUE(queue, root)
        root.visited := TRUE
    ELSE
        IF root.left <> NULL AND root.left.visited = FALSE :
            CALL LeafbyLeaf(queue, root.left)
        ENDIF
        IF root.right <> NULL AND root.right.visited = FALSE :
            CALL LeafbyLeaf(queue, root.right)
        ENDIF
    ENDIF
END

ACTION Traversal2 (root)
LET
    root : POINTER TO NODE;
    queue : QUEUE;
    node : POINTER TO NODE;
BEGIN
    IF root = NULL :
        RETURN
    ENDIF

    CALL CREATEQUEUE(queue)

    IF queue = NULL :
        WRITE("Failed to create queue. Insufficient memory.")
        RETURN
    ENDIF

    WHILE root.visited = FALSE :
        CALL LeafbyLeaf(queue, root)
        WHILE EMPTY_QUEUE(queue) = FALSE :
            node := DEQUEUE(queue)
            WRITE(node.data)
        ENDWHILE
    ENDWHILE

    CALL DESTROYQUEUE(queue)
END

