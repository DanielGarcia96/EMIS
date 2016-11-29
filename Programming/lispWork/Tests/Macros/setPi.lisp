(load "totalall.lisp")
(defmacro PiThis(num)
(* num 3.1459))

(setq num (TOTALALL '(1 (2 3) 4)))
(print num)
(print (PiThis 10))
(setq num (PiThis 10))
(print num)
