;テスト用木
(define TREE '(1 (2 (3 4)) 6 (7 8 9)) )
(define TREE00 '(1 2 3 4 5))

;課題1-1関連
(define mymap
  (lambda (fn ls)
    (if (null? ls)
        '()
        (cons (fn (car ls))
              (map fn (cdr ls)))
        )))

;課題1-1回答
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

;課題1-1テスト
(map-tree even? TREE)
;(#f (#t (#f #t)) #t (#f #t #f))
(map-tree (lambda (x) (* x x)) TREE)
;(1 (4 (9 16)) 36 (49 64 81))
(map-tree even? TREE00)
;(#f #t #f #t #f)
(map-tree (lambda (x) (* x x)) TREE00)
;(1 4 9 16 25)

;課題1-2回答
(define map-tree2
  (lambda (fn tree)
    (cond ((null? tree) '())
          ((pair? tree) [])
          ;map-treeでは引数が2こ必要なのでmapを使用することができない
          ;map-treeで受け取っていた引数fnは全く変更されていない。
          ;したがって計算対象の木のみを一つの引数として受け取るようにして
          ;この引数の木とfnの二つを使って、map-tree2を呼び出す名前なし関数をmapに与えるようにする
          ;また、mapに与える関数は
          ;(lambda (t) (map-tree2 fn t))
          ;である
          (else (fn tree))
          )))

;課題1-2テスト
(map-tree2 even? TREE)
;(#f (#t (#f #t)) #t (#f #t #f))
(map-tree2 (lambda (x) (* x x)) TREE)
;(1 (4 (9 16)) 36 (49 64 81))
(map-tree2 even? TREE00)
;(#f #t #f #t #f)
(map-tree2 (lambda (x) (* x x)) TREE00)
;(1 4 9 16 25)