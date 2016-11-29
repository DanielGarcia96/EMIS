(defmacro PRINT_NOT_EQ (first &rest others)
 (PROG ((COUNT 0))
   (DOLIST (item others)
     (if (equal item first)
            (setf count (+ 1 count))
            (print item)
     )
   )
   (print (list 'occ 'of first '= count))
 )
)

(PRINT_NOT_EQ DOG CAT DOG MONKEY DOG LION)
(PRINT_NOT_EQ DOG CAT DOG MONKEY DOG LION)