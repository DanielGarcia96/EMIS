(DEFUN REVSENT (S) (
      COND ((= 0 (LENGTH S)))
            ((= 1 (LENGTH S)) (CHAR S 0))
            (T (CONCATENATE 'STRING (STRING (REVSENT (SUBSEQ S 1))) 
                                    (STRING (CHAR S 0))))
   )
)

(FORMAT T "
(FORMAT T "Reversed: ~s
(FORMAT T "Language Implementation: ~s