/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:33:10 by karai             #+#    #+#             */
/*   Updated: 2024/12/22 16:33:33 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
int oldfd = -1; // 無効なファイルディスクリプタ
int newfd = 1;  // 標準出力（通常は有効）

// dup2を試す
if (dup2(oldfd, newfd) == -1) {
    // エラーを表示
    perror("dup2 failed");
    // 明示的にエラーコードを返して終了
    return 1;
}

// ここには到達しない（dup2が成功する場合のみ）
printf("This will not be printed if dup2 fails.\\n");

return 0;
}
