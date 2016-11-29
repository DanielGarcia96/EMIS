(defun REPTOP (match rep L) 
   (cond ((NULL L) '())
         (
            (EQL match (CAR L))
            (CONS rep ( REPTOP match rep (CDR L) ))
         )
         (  T ( CONS ( CAR L ) ( REPTOP match rep ( CDR L ) ) )  )
   )
)

( reptop 'i 'o '(m i s s i s s i p p i) )
( reptop 'i 'o '(m i s s (i s s) i p p i) )
