(define kakeizu
  (read
   (open-input-file "./kakeizu")))

"入力"
kakeizu
"入力"

(define get-depth
  (lambda(tree num)
    (cond ((= num 1)
              ()  
          );1になった時 -> この時は出力される
          (else
              ()
          );1でない時 -> この時は息子をたどるようにする
    )
  )
)

(get-depth kakeizu 3)
