(define kakeizu
  (read
   (open-input-file "./kakeizu")))

(define get-depth
  (lambda(tree num)
    (cond ((= num 1)
              (map car (cdr tree))
          );1になった時 -> この時は出力される
          ((null? tree)
          )
          (else (apply append (map (lambda (t) (get-depth t (- num 1))) (cdr tree)))
          );1でない時 -> この時は息子をたどるようにする
    )
  )
)

"get-depth 実行結果 begin"
"get-depth kakeizu 1 <- executed"
(get-depth kakeizu 1)
"get-depth kakeizu 3 <- executed"
(get-depth kakeizu 3)
"get-depth kakeizu 6 <- executed"
(get-depth kakeizu 6)
"get-depth 実行結果 end"

(define equal_list
  (lambda (tree name)
    (cond
         ((null? tree)
          #f
         )
         ((equal? name (car tree))
          #t
         )
         (else (equal_list (cdr tree) name)
         )
    )
  )
)


(define search
  (lambda (tree name depth)
    (cond ((null? tree)
           0
          )
          ((= depth 10)
           0
          )
          ((equal_list (get-depth tree depth) name)
           depth
          )
          (else (search tree name (+ depth 1))
          )
    )
  )
)

(define get-cousin
  (lambda (tree name)
    (get-depth tree (search tree name 1))
  )
)

"get-cousin 実行結果 begin"
"(get-cousin kakeizu '秀忠 <- executed"
(get-cousin kakeizu '秀忠)
"(get-cousin kakeizu '吉宗 <- executed"
(get-cousin kakeizu '吉宗)
"(get-cousin kakeizu '家継 <- executed"
(get-cousin kakeizu '家継)
"get-cousin 実行結果 end"
