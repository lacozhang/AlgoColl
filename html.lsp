(defmacro as (tag content)
  `(format t "<~(~A~)>~A</~(~A~)>"
		   ',tag ,content ',tag))

(defmacro with (tag &rest body)
  `(progn
	 (format t "~&<&~(~A~)>" ',tag)
	 @body
	 (format t "~&</~(~A~)>" ',tag)))


