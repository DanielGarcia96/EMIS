(defun TOTALTOP (L)
   (cond ((NULL L) 0)
         ( T (+ (CAR L) ( TOTALTOP (CDR L) ) ) )
   )
)

(print (totaltop '(5 10 15)))
