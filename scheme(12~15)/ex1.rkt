(define numlist
  (lambda (x)
    (if (= x 1) '(1) (cons x (numlist (- x 1))))
    ))

#(numlist 3)
(numlist 3)
#(numlist 5)
(numlist 5)

(define myappend
  (lambda (x)
    (apply append x)
    )
  )

#(myappend '((1 2 3) (a b) (c d)) )
(myappend '((1 2 3) (a b) (c d)) )

(define times
  (lambda (num list)
    (map (lambda (sub) (* num sub)) list)
    ))

#(times 3 '(1 2 3 4))
(times 3 '(1 2 3 4))
#(times 5 '(2 8 5))
(times 5 '(2 8 5))

(define sqr
  (lambda (num) (* num num)
    ))

(define rms
  (lambda (data) (sqrt (/ (apply + (map sqr data)) (length data)))
    ))

#(rms '(1 2 3))
(rms '(1 2 3))
#(rms '(5 1 1))
(rms '(5 1 1))