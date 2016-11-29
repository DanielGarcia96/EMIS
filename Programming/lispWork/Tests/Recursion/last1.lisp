(defun LAST1 (L)
   (cond((NULL (cdr L)) (car L))
        (T (LAST1 (cdr L)))
      
   )
)

(LAST1 '(A B D))
