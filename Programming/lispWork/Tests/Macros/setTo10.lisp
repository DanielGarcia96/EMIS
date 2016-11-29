(defmacro setTo10(num)
  (list 'setq num 10)
)
(defmacro setq2 (v1 v2 e)
    (list 'progn (list 'setq v1 e) (list 'setq v2 e))
)
(setq x 25)
(print x)
(setTo10 x)
(print x)
(setq2 x y (+ 2 3))
(print x)