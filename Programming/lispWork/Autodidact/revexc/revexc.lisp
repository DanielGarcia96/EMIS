(DEFMACRO REVEXC (&rest L)
    (LET* ((LT (GENSYM)) (LT  L))
          ( cond ( (ATOM (CAR LT)) (print "ATOM") `(dolist (ITEM (REVERSE ,@LT)) (eval ITEM)) )
                 ( T (print "NOT ATOM") `(dolist (ITEM (REVERSE (LIST ,@LT))) ITEM))
          )
    )
)
(setf LST '((print "3") (print "2") (print "1")))
(dolist (ITEM LST) (eval ITEM))
(format T "");

(REVEXC LST)
(REVEXC (print "1") (print "2") (print "3"))
;(print (REVERSE (LIST '(PRINT "1") '(PRINT "2") '(PRINT "3"))))
