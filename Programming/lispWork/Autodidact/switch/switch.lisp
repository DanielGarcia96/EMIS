(defmacro switch (value &rest pairs)
    (let ((v (gensym)) (v value) (p (gensym)))
         `(dolist (p (list ,@pairs)) 
           (if (eql v p) (eval (car(cdr p)))))
    )
)

(setf x 5)
(switch x
        ( 5 (print "it is 5") )
        ( (+ 4 6) (print "it is 10") )
        ( default (print "default") ) )
