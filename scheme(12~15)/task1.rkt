(define TREE '(1 (2 (3 4)) 6 (7 8 9)) )

(define mymap
  (lambda (fn ls)
    (if (null? ls)
        '()
        (cons (fn (car ls))
              (map fn (cdr ls)))
        )))

(define map-tree
  (lambda (fn tree)
    (cond ((null? tree) '())
          ((pair? tree) [])
          (else (fn tree))
          )))