(defun MYFIRST (L)
   (CAR L)
)

(defun MYSECOND(L)
   (CADR L)
)

(defun MAX2(x y)
   (cond ((> x y) x)
      (T y)
   )
)

(SETF A 10 B 5)
(print (MAX2 A ( * B 5)))
