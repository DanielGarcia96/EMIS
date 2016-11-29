(defun CARDINALITY (L)
   (cond ((NULL L) 0)
         (T (+ 1 
               (CARDINALITY (cdr L)))
         )
   )
)

(CARDINALITY '(x y z))
(CARDINALITY '((x y) x))
(CARDINALITY '())
