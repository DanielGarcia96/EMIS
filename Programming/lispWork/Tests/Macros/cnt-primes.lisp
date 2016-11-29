(defmacro += (n a)
    (list 'setf n `(+ ,n ,a))
)

(defun prime (n)
    (let* ((r (gensym)) (r T))
          (dotimes (c n) if (AND (NOT (= c 0)) (= (mod n c) 0)) (setf r NIL))
          r
    )
)

(defmacro do-primes (c &rest bodies) 
    (let ((n (gensym)) (item (gensym)))
        `(dotimes (n ,c) if (prime n) (dolist (item (list ,@bodies)) (eval item)))
    )
)

(setf c 11)
(setf x 1)
(do-primes 11 (print x) (+= x 1))
