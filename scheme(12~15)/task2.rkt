(define kakeizu
  (read
   (open-input-file "./kakeizu")))

"入力 begin"
kakeizu
"入力 end"

"cdr test begin"
(cdr kakeizu)
"cdr test end"


(define get-depth
  (lambda(tree num)
    (cond ((= num 1)
              (map car (cdr tree))
          );1になった時 -> この時は出力される
          ((null? tree)
          )
          (else (map (lambda (t) (get-depth t (- num 1))) (cdr tree))
          );1でない時 -> この時は息子をたどるようにする
    )
  )
)

"get-depth kakeizu 1 begin"
(get-depth kakeizu 1)
"get-depth kakeizu 1 end"

"get-depth kakeizu 3 begin"
(get-depth kakeizu 3)
"get-depth kakeizu 3 end"

"get-depth kakeizu 6 begin"
(get-depth kakeizu 6)
"get-depth kakeizu 6 end"