(DEFUN REVSENT (S) (
      COND ((= 0 (LENGTH S)))
            ((= 1 (LENGTH S)) (CHAR S 0))
            (T (CONCATENATE 'STRING (STRING (REVSENT (SUBSEQ S 1))) 
                                    (STRING (CHAR S 0))))
   )
)

(FORMAT T "Originally ~s" "3 2 1")
(FORMAT T "Reversed: ~s" (REVSENT "3 2 1"))
(FORMAT T "Language Implementation: ~s" (REVERSE "3 2 1"))
