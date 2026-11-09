#include <stdio.h>
#include <string.h>


struct Ouvinte {
    int idOuvinte;
    char nome[50];
    char telefone[20];
    int totalEmprestimos; 
    int ativo;
};
struct Ouvinte listaOuvintes[50];
int totalOuvintes = 0;

struct Album {
    int idAlbum;
    char titulo[50];
    char artista[40];
    float notaAvaliacao; 
    int disponivel;
};
struct Album catalogoAlbuns[50];
int totalAlbuns = 0;

struct Acessorio {
    int idAcessorio;
    char descricao[40];
    char marca[40];
    float custoCompra;
    int quantidadeEstoque;
};
struct Acessorio estoqueAcessorios[50];
int totalAcessorios = 0;
int proximoIdAcessorio = 1;

struct Reproducao {
    int idReproducao;
    int idOuvinte;
    int idAlbum;
    int diasEmprestado; 
    float taxaAtraso; 
};
struct Reproducao historicoReproducoes[50];
int totalReproducoes = 0;


void exibirCabecalho() {
    printf("\n======================================================\n");
    printf("    CDTECA    \n");
    printf("======================================================\n");
}
// MODULO 1: PERSPECTIVA DE OUVINTES (COLEGAS)
// Autor: Integrante A (Gabriel Albini Lazzarotto RGM:42234051 )
void cadastrarOuvinte() {
    if (totalOuvintes >= 50) {
        printf("\n[ERRO] Limite de 50 ouvintes atingido!\n");
        return;
    }
    listaOuvintes[totalOuvintes].idOuvinte = totalOuvintes + 1;
    printf("\nNome (sem espacos, use _): ");
    scanf("%s", listaOuvintes[totalOuvintes].nome);
    printf("Telefone: ");
    scanf("%s", listaOuvintes[totalOuvintes].telefone);
    listaOuvintes[totalOuvintes].totalEmprestimos = 0;
    listaOuvintes[totalOuvintes].ativo = 1;
    printf("\nOuvinte cadastrado com ID %d!\n", listaOuvintes[totalOuvintes].idOuvinte);
    totalOuvintes++;
}

void listarOuvintes() {
    int i, achou = 0;
    printf("\n--- LISTA DE OUVINTES ---\n");
    for (i = 0; i < totalOuvintes; i++) {
        if (listaOuvintes[i].ativo == 1) {
            printf("ID: %d | Nome: %s | Tel: %s | Emprestimos Ativos: %d\n",
                   listaOuvintes[i].idOuvinte, listaOuvintes[i].nome,
                   listaOuvintes[i].telefone, listaOuvintes[i].totalEmprestimos);
            achou = 1;
        }
    }
    if (achou == 0) printf("Nenhum ouvinte cadastrado.\n");
}

void editarOuvinte() {
    int id, i, encontrado = 0;
    printf("\nID do ouvinte a editar: ");
    scanf("%d", &id);
    for (i = 0; i < totalOuvintes; i++) {
        if (listaOuvintes[i].idOuvinte == id && listaOuvintes[i].ativo == 1) {
            printf("Novo telefone: ");
            scanf("%s", listaOuvintes[i].telefone);
            printf("\nOuvinte atualizado!\n");
            encontrado = 1;
        }
    }
    if (encontrado == 0) printf("\n[ERRO] Ouvinte nao encontrado.\n");
}

void removerOuvinte() {
    int id, i, encontrado = 0;
    printf("\nID do ouvinte a remover: ");
    scanf("%d", &id);
    for (i = 0; i < totalOuvintes; i++) {
        if (listaOuvintes[i].idOuvinte == id && listaOuvintes[i].ativo == 1) {
            listaOuvintes[i].ativo = 0;
            printf("\nOuvinte removido!\n");
            encontrado = 1;
        }
    }
    if (encontrado == 0) printf("\n[ERRO] Ouvinte nao encontrado.\n");
}

void moduloOuvintes() {
    int opcaoOuvinte;
    do {
        printf("\n--- [MODULO 1: GESTAO DE OUVINTES (Integrante A)] ---\n");
        printf("1. Cadastrar Novo Ouvinte\n");
        printf("2. Listar / Buscar Ouvintes\n");
        printf("3. Editar Telefone do Ouvinte\n");
        printf("4. Remover Ouvinte\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma acao: ");
        scanf("%d", &opcaoOuvinte);

        switch (opcaoOuvinte) {
            case 1: cadastrarOuvinte(); break;
            case 2: listarOuvintes(); break;
            case 3: editarOuvinte(); break;
            case 4: removerOuvinte(); break;
            case 0: printf("\nRetornando ao menu principal...\n"); break;
            default: printf("\n[ERRO] Opcao invalida!\n");
        }
    } while (opcaoOuvinte != 0);
}
// MODULO 2: PERSPECTIVA DE CATÁLOGO DE ÁLBUNS / CDs
// Autor: Integrante B (Henrique Tebecherani Moreno RGM:49643851 )
void cadastrarAlbum() {
    if (totalAlbuns >= 50) {
        printf("\n[ERRO] Limite de 50 albuns atingido na CDteca!\n");
        return;
    }
    catalogoAlbuns[totalAlbuns].idAlbum = totalAlbuns + 1;
    printf("\nTitulo do Album (sem espacos, use _): ");
    scanf("%s", catalogoAlbuns[totalAlbuns].titulo);
    printf("Artista/Banda (sem espacos, use _): ");
    scanf("%s", catalogoAlbuns[totalAlbuns].artista);
    printf("Sua nota de avaliacao (ex: 9.5): ");
    scanf("%f", &catalogoAlbuns[totalAlbuns].notaAvaliacao);
    catalogoAlbuns[totalAlbuns].disponivel = 1; 
    printf("\nAlbum cadastrado com Sucesso! ID: %d\n", catalogoAlbuns[totalAlbuns].idAlbum);
    totalAlbuns++;
}

void listarAlbuns() {
    int i, achou = 0;
    printf("\n--- CATALOGO DE ALBUNS DA CDTECA ---\n");
    for (i = 0; i < totalAlbuns; i++) {
        if (catalogoAlbuns[i].disponivel == 1) {
            printf("ID: %d | Titulo: %s | Artista: %s | Nota: %.1f\n",
                   catalogoAlbuns[i].idAlbum, catalogoAlbuns[i].titulo,
                   catalogoAlbuns[i].artista, catalogoAlbuns[i].notaAvaliacao);
            achou = 1;
        }
    }
    if (achou == 0) printf("Nenhum album disponivel na sua CDteca no momento.\n");
}

void editarAlbum() {
    int id, i, encontrado = 0;
    printf("\nDigite o ID do album que deseja editar: ");
    scanf("%d", &id);
    for (i = 0; i < totalAlbuns; i++) {
        if (catalogoAlbuns[i].idAlbum == id && catalogoAlbuns[i].disponivel == 1) {
            printf("Album encontrado: %s - %s\n", catalogoAlbuns[i].titulo, catalogoAlbuns[i].artista);
            printf("Nova nota de avaliacao: ");
            scanf("%f", &catalogoAlbuns[i].notaAvaliacao);
            printf("\nNota do album atualizada com sucesso!\n");
            encontrado = 1;
        }
    }
    if (encontrado == 0) printf("\n[ERRO] Album nao encontrado ou ja foi removido.\n");
}

void removerAlbum() {
    int id, i, encontrado = 0;
    printf("\nDigite o ID do album para remover da CDteca: ");
    scanf("%d", &id);
    for (i = 0; i < totalAlbuns; i++) {
        if (catalogoAlbuns[i].idAlbum == id && catalogoAlbuns[i].disponivel == 1) {
            catalogoAlbuns[i].disponivel = 0; 
            printf("\nAlbum removido da estante com sucesso!\n");
            encontrado = 1;
        }
    }
    if (encontrado == 0) printf("\n[ERRO] Album nao encontrado.\n");
}

void moduloAlbuns() {
    int opcaoAlbum;
    do {
        printf("\n--- [MODULO 2: CATALOGO DE ALBUNS / CDs (Integrante B)] ---\n");
        printf("1. Cadastrar Novo Album\n");
        printf("2. Listar Albuns Disponiveis\n");
        printf("3. Editar Nota de Avaliacao\n");
        printf("4. Remover Album da Estante\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma acao: ");
        scanf("%d", &opcaoAlbum);

        switch (opcaoAlbum) {
            case 1: cadastrarAlbum(); break;
            case 2: listarAlbuns(); break;
            case 3: editarAlbum(); break;
            case 4: removerAlbum(); break;
            case 0: printf("\nRetornando ao menu principal...\n"); break;
            default: printf("\n[ERRO] Opcao invalida no Modulo de Albuns!\n");
        }
    } while (opcaoAlbum != 0);
}
// MODULO 3: ESTOQUE DE ACESSORIOS (Capinhas, Pilhas, Flanelas)
// Autor: Integrante C (Lucas pinto do nascimento  RGM:49316982 )
void registrarAcessorio() {
    if (totalAcessorios >= 50) {
        printf("\n[ERRO] Limite de 50 acessorios atingido!\n");
        return;
    }
    estoqueAcessorios[totalAcessorios].idAcessorio = proximoIdAcessorio;
    printf("\nDescricao (sem espacos, use _): ");
    scanf("%s", estoqueAcessorios[totalAcessorios].descricao);
    printf("Marca (sem espacos, use _): ");
    scanf("%s", estoqueAcessorios[totalAcessorios].marca);
    printf("Custo de compra unitario: ");
    scanf("%f", &estoqueAcessorios[totalAcessorios].custoCompra);
    printf("Quantidade em estoque: ");
    scanf("%d", &estoqueAcessorios[totalAcessorios].quantidadeEstoque);
    printf("\nAcessorio registrado com ID %d!\n", proximoIdAcessorio);
    proximoIdAcessorio++;
    totalAcessorios++;
}

void consultarAcessorios() {
    int i;
    printf("\n--- ESTOQUE DE ACESSORIOS ---\n");
    if (totalAcessorios == 0) printf("Nenhum acessorio cadastrado.\n");
    for (i = 0; i < totalAcessorios; i++) {
        printf("ID: %d | %s | Marca: %s | Custo: R$ %.2f | Estoque: %d un\n",
               estoqueAcessorios[i].idAcessorio, estoqueAcessorios[i].descricao,
               estoqueAcessorios[i].marca, estoqueAcessorios[i].custoCompra,
               estoqueAcessorios[i].quantidadeEstoque);
    }
}

void atualizarAcessorio() {
    int id, i, encontrado = 0;
    printf("\nID do acessorio a atualizar: ");
    scanf("%d", &id);
    for (i = 0; i < totalAcessorios; i++) {
        if (estoqueAcessorios[i].idAcessorio == id) {
            printf("Nova quantidade em estoque: ");
            scanf("%d", &estoqueAcessorios[i].quantidadeEstoque);
            printf("\nEstoque atualizado!\n");
            encontrado = 1;
        }
    }
    if (encontrado == 0) printf("\n[ERRO] Acessorio nao encontrado.\n");
}

void baixaAcessorio() {
    int id, i, j, encontrado = 0;
    printf("\nID do acessorio para dar baixa: ");
    scanf("%d", &id);
    for (i = 0; i < totalAcessorios && encontrado == 0; i++) {
        if (estoqueAcessorios[i].idAcessorio == id) {
            for (j = i; j < totalAcessorios - 1; j++) {
                estoqueAcessorios[j] = estoqueAcessorios[j + 1];
            }
            totalAcessorios--;
            encontrado = 1;
            printf("\nBaixa realizada!\n");
        }
    }
    if (encontrado == 0) printf("\n[ERRO] Acessorio nao encontrado.\n");
}

void moduloAcessorios() {
    int opcaoAcessorio;
    do {
        printf("\n--- [MODULO 3: ESTOQUE DE ACESSORIOS (Integrante C)] ---\n");
        printf("1. Registrar Novo Acessorio (Capinha, Pilha, etc)\n");
        printf("2. Consultar Estoque\n");
        printf("3. Atualizar Quantidade\n");
        printf("4. Dar Baixa / Remover Acessorio\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma acao: ");
        scanf("%d", &opcaoAcessorio);

        switch (opcaoAcessorio) {
            case 1: registrarAcessorio(); break;
            case 2: consultarAcessorios(); break;
            case 3: atualizarAcessorio(); break;
            case 4: baixaAcessorio(); break;
            case 0: printf("\nRetornando ao menu principal...\n"); break;
            default: printf("\n[ERRO] Opcao invalida!\n");
        }
    } while (opcaoAcessorio != 0);
}
// MODULO 4: EMPRESTIMOS E RELATORIOS ANALITICOS
// Autor: Integrante D (João Pedro Lobo Salomão RGM:)
// Autor: Integrante D (Gabriel Cordeiro de Oliveira RGM:)

void registrarEmprestimo() {
    int idOuv, idAlb, dias, i, posAlbum = -1, ouvinteOk = 0;
    if (totalReproducoes >= 50) {
        printf("\n[ERRO] Limite de 50 emprestimos atingido!\n");
        return;
    }
    printf("\nID do Ouvinte: ");
    scanf("%d", &idOuv);
    printf("ID do Album (CD): ");
    scanf("%d", &idAlb);
    printf("Dias de Emprestimo previstos: ");
    scanf("%d", &dias);

    for (i = 0; i < totalOuvintes; i++) {
        if (listaOuvintes[i].idOuvinte == idOuv && listaOuvintes[i].ativo == 1) {
            ouvinteOk = 1;
        }
    }
    for (i = 0; i < totalAlbuns; i++) {
        if (catalogoAlbuns[i].idAlbum == idAlb && catalogoAlbuns[i].disponivel == 1) {
            posAlbum = i;
        }
    }
    if (ouvinteOk == 0 || posAlbum == -1 || dias <= 0) {
        printf("\n[ERRO] Ouvinte ou Album inexistente/indisponivel, ou dias invalidos.\n");
        return;
    }
    
    historicoReproducoes[totalReproducoes].idReproducao = totalReproducoes + 1;
    historicoReproducoes[totalReproducoes].idOuvinte = idOuv;
    historicoReproducoes[totalReproducoes].idAlbum = idAlb;
    historicoReproducoes[totalReproducoes].diasEmprestado = dias;
    
    catalogoAlbuns[posAlbum].disponivel = 0; 

    printf("\nEmprestimo %d registrado! Album '%s' retirado da estante.\n",
           historicoReproducoes[totalReproducoes].idReproducao,
           catalogoAlbuns[posAlbum].titulo);
           
    totalReproducoes++;
}

void listarEmprestimos() {
    int i;
    printf("\n--- HISTORICO DE EMPRESTIMOS ---\n");
    if (totalReproducoes == 0) printf("Nenhum emprestimo registrado.\n");
    
    for (i = 0; i < totalReproducoes; i++) {
        printf("Registro %d | ID Ouvinte: %d | ID Album: %d | Dias: %d\n",
               historicoReproducoes[i].idReproducao, historicoReproducoes[i].idOuvinte,
               historicoReproducoes[i].idAlbum, historicoReproducoes[i].diasEmprestado);
    }
}

void moduloEmprestimosRelatorios() {
    int opcaoVenda;
    do {
        printf("\n--- [MODULO 4: EMPRESTIMOS E RELATORIOS (Integrante D)] ---\n");
        printf("1. Registrar Novo Emprestimo de CD\n");
        printf("2. Listar Historico Geral\n");
        printf("3. Devolver CD (Em construcao)\n");
        printf("4. [RELATORIO] Album Mais Ouvido (Requisitado)\n");
        printf("5. [RELATORIO] Ouvinte VIP (Maior Numero de Emprestimos)\n");
        printf("6. [RELATORIO] Historico de um Ouvinte Especifico\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma acao: ");
        scanf("%d", &opcaoVenda);

        switch (opcaoVenda) {
            case 1: registrarEmprestimo(); break;
            case 2: listarEmprestimos(); break;
            case 3: printf("\n[Em construcao] Rotina de devolucao...\n"); break;
            case 4:
                printf("\n--- ALBUM MAIS OUVIDO / REQUISITADO ---\n");
                if (totalReproducoes == 0) {
                    printf("Nenhum emprestimo registrado ainda.\n");
                } else {
                    int contagem[50] = {0}; 
                    for (int i = 0; i < totalReproducoes; i++) {
                        int idBuscado = historicoReproducoes[i].idAlbum;
                        for (int j = 0; j < totalAlbuns; j++) {
                            if (catalogoAlbuns[j].idAlbum == idBuscado) {
                                contagem[j]++; 
                            }
                        }
                    }
                    int max = 0, indiceCampeao = -1;
                    for (int j = 0; j < totalAlbuns; j++) {
                        if (contagem[j] > max) {
                            max = contagem[j];
                            indiceCampeao = j;
                        }
                    }
                    if (indiceCampeao != -1) {
                        printf("O Album Campeao e: %s (Artista: %s) com %d reproducoes!\n", 
                               catalogoAlbuns[indiceCampeao].titulo, 
                               catalogoAlbuns[indiceCampeao].artista, max);
                    }
                }
                break;
            case 5:
                printf("\n--- OUVINTE VIP (MAIS EMPRESTIMOS) ---\n");
                if (totalReproducoes == 0) {
                    printf("Nenhum emprestimo registrado ainda.\n");
                } else {
                    int contagemOuvinte[50] = {0}; 
                    for (int i = 0; i < totalReproducoes; i++) {
                        int idBuscado = historicoReproducoes[i].idOuvinte;
                        for (int j = 0; j < totalOuvintes; j++) {
                            if (listaOuvintes[j].idOuvinte == idBuscado) {
                                contagemOuvinte[j]++;
                            }
                        }
                    }
                    int maxOuvinte = 0, indiceVIP = -1;
                    for (int j = 0; j < totalOuvintes; j++) {
                        if (contagemOuvinte[j] > maxOuvinte) {
                            maxOuvinte = contagemOuvinte[j];
                            indiceVIP = j;
                        }
                    }
                    if (indiceVIP != -1) {
                        printf("O Ouvinte VIP e: %s com %d albuns retirados!\n", 
                               listaOuvintes[indiceVIP].nome, maxOuvinte);
                    }
                }
                break;
            case 6:
                printf("\n--- FILTRAR REPRODUCOES POR OUVINTE ---\n");
                int idBusca, achouHistorico = 0;
                printf("Digite o ID do Ouvinte: ");
                scanf("%d", &idBusca);
                for (int i = 0; i < totalReproducoes; i++) {
                    if (historicoReproducoes[i].idOuvinte == idBusca) {
                        printf("Registro ID: %d | ID Album: %d | Dias Emprestado: %d\n", 
                               historicoReproducoes[i].idReproducao,
                               historicoReproducoes[i].idAlbum,
                               historicoReproducoes[i].diasEmprestado);
                        achouHistorico = 1;
                    }
                }
                if (achouHistorico == 0) {
                    printf("Nenhum historico encontrado para este ID.\n");
                }
                break;
            case 0: printf("\nRetornando ao menu principal...\n"); break;
            default: printf("\n[ERRO] Opcao invalida!\n");
        }
    } while (opcaoVenda != 0);
}

int main() {
    int opcaoPrincipal;
    do {
        exibirCabecalho();
        printf("SELECIONE A PERSPECTIVA DO SISTEMA:\n");
        printf("1. Modulo de Ouvintes/Colegas (Integrante A)\n");
        printf("2. Modulo de Albuns / CDs (Integrante B)\n");
        printf("3. Modulo de Acessorios da CDteca (Integrante C)\n");
        printf("4. Modulo de Emprestimos e Relatorios (Integrante D)\n");
        printf("0. Encerrar o Sistema\n");
        printf("------------------------------------------------------\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcaoPrincipal);

        switch (opcaoPrincipal) {
            case 1: moduloOuvintes(); break;
            case 2: moduloAlbuns(); break;
            case 3: moduloAcessorios(); break;
            case 4: moduloEmprestimosRelatorios(); break;
            case 0: printf("\nEncerrando a CDteca Pessoal... Ate logo!\n"); break;
            default: printf("\n[ALERTA] Opcao invalida! Digite um numero de 0 a 4.\n");
        }
    } while (opcaoPrincipal != 0);
    return 0;
}