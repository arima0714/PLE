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
          ((pair? tree) (cons (map-tree fn (car tree)) (map-tree fn (cdr tree))))
          ;木が与えられた場合の処理。
          ;map-treeは元の木と同じ形状の木が答えとなる。
          ;したがって空欄部分の定義は、ドット対のcar部とcdr部の両方に再帰的に適用する。
          ;そして、その結果をconsで繋げる計算となるはずである。
          (else (fn tree))
          )))

(map-tree even? TREE)
(map-tree (lambda (x) (* x x) TREE))