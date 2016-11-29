;;; factorial of N
(defun FACTORIAL(n)
   (cond ((ZEROP N) 1)
      (T (* N
            (FACTORIAL (- N 1))
         )
      )
   )
)

(print (FACTORIAL 3))
