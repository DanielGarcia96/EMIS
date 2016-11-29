(loop for x in '(tom dick harry)
   do (format t " ~s" x)
)

(loop for a from 10 to 20
   do (print a)
)

(format t "")

(loop for x from 1 to 20
   if(evenp x) do (format t "~s " x)
)
