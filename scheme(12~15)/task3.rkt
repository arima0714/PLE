"Exercise3-1"

(define diff
  (lambda (func)
    (cond
         ((number? func)
          0
         )
         ((equal? 'x func)
          1
         )
         ((equal? '+ func)
          '+
         )
         ((equal? '- func)
          '-
         )
         ((equal? '* (car func))
          `(+ (* ,(cadr func) ,(diff (caddr func))) (* ,(diff (cadr func)) ,(caddr func)))
         )
         ((equal? '** (car func))
          `(* ,(caddr func) (* ,(diff (cadr func)) (** ,(cadr func) ,(- (caddr func) 1))))
         )
         (else
          (map diff func)
         )
    )
  )
)

"(cadr 式)で第1引数をとる"
"(caddr 式)で第2引数をとる"

#(diff 5)
(diff 5)
#(diff 'x)
(diff 'x)
#(diff '(+ x 5))
(diff '(+ x 5))
#(diff '(- x 5))
(diff '(- x 5))
#(diff '(* 5 x))
(diff '(* 5 x))
#(diff '(** x 2))
(diff '(** x 2))
#(diff '(+ (** x 3) (* 2 x) 4))
(diff '(+ (** x 3) (* 2 x) 4))
#(diff '(** (* x 3) 2))
(diff '(** (* x 3) 2))
#(diff '(* (+ x 2) (- (** x 2) x)))
(diff '(* (+ x 2) (- (** x 2) x)))

"Exercise3-2"

(define ** expt)

(define fx '(+ (** x 2) (* 4 x) 3) )
(define fdx (diff fx))


(define tangent
  (lambda (func Xkey)
   `(+
      (* ,((eval `(lambda(x) ,(diff func)) (interaction-environment)) Xkey) x)
      ,(- ((eval `(lambda(x) ,func) (interaction-environment)) Xkey) (* Xkey ((eval `(lambda(x) ,(diff func)) (interaction-environment)) Xkey)))
     )
  )
)

#(tangent '(+ (** x 3) (* -2 (** x 2)) 9) 2)
(diff '(+ (** x 3) (* -2 (** x 2)) 9))
#(tangent '(+ (** x 3) (* -2 (** x 2)) 9) 2)
(tangent '(+ (** x 3) (* -2 (** x 2)) 9) 2)

"Exercise3-3"



#(diff2 'x 'x)
(diff2 'x 'x)
#(diff2 'y 'x)
(diff2 'y 'x)