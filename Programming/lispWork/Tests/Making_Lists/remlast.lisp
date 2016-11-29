(defun REMLAST(L)
   (cond ( (NULL L) NIL )
      ( (NULL (CDR L)) NIL )
      ( T (CONS (CAR L) (REMLAST (CDR L)) ) )
   )
)

(setf LIS '(A B C D))
(setf LIS (REMLAST LIS))
(print LIS)
